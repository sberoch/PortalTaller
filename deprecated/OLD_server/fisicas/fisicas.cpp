#include "fisicas.h"

#include <cstdint>

#include "../server_config.h"

#include "posicion.h"
#include "direccion.h"
#include "formas/forma.h"

#include "../entidades/entidad.h"
#include "../terrenos/terreno.h"
#include "../terrenos/bloque_metal_cuadrado.h"

#include "transformaciones/agregar_entidad.h"
#include "transformaciones/destruir_entidad.h"
#include "transformaciones/teletransportar_entidad.h"
#include "transformaciones/agregar_bloque_metal_cuadrado.h"

Fisicas::Fisicas() : 
    gravedad_(CONFIG.GRAVEDAD_X, CONFIG.GRAVEDAD_Y),
    mundo_(new b2World(gravedad_)) {
}

Fisicas::Fisicas(b2World* unMundo) : mundo_(unMundo) {
}

Fisicas::~Fisicas() {
}

void Fisicas::agregar(Identificable& unIdentificable, Posicion& p) {
    unIdentificable.agregateEn(*this, p);
}

void Fisicas::agregar(Entidad& unaEntidad, Posicion& p) {	
	transformaciones_.push(std::shared_ptr<Transformacion>(new AgregarEntidad(*this, unaEntidad, p)));	
}

void Fisicas::agregarPosta(Entidad& unaEntidad, Posicion& p) {
	b2BodyDef bodyDef;
	bodyDef.bullet = true;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(p.getX(), p.getY());
	bodyDef.userData = &unaEntidad;
	b2Body* body = mundo_->CreateBody(&bodyDef);
	unaEntidad.forma()->inicializar(body);

	identificables_[unaEntidad.uuid()] = body;
}

void Fisicas::agregar(BloqueMetalCuadrado& b, Posicion& p) {
    transformaciones_.push(std::shared_ptr<Transformacion>(new AgregarBloqueMetalCuadrado(*this, b, p)));
}

void Fisicas::agregarPosta(BloqueMetalCuadrado& b, Posicion& p) {
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(p.getX(), p.getY());
	groundBodyDef.userData = &b;
    b2Body* groundBody = mundo_->CreateBody(&groundBodyDef);
    b.forma()->inicializar(groundBody);
	identificables_[b.uuid()] = groundBody;
}

void Fisicas::destruir(Entidad& unaEntidad) {
	transformaciones_.push(std::shared_ptr<Transformacion>(new DestruirEntidad(*this, unaEntidad)));
}

void Fisicas::destruirPosta(Entidad& unaEntidad) {
	uint16_t uuid = unaEntidad.uuid();
	b2Body* b2Cuerpo = identificables_[uuid];
	if (b2Cuerpo) {
		mundo_->DestroyBody(b2Cuerpo);
		identificables_.erase(uuid);
	}
}

void Fisicas::teletransportar(Entidad& unaEntidad, Posicion& p, Direccion& d) {
	transformaciones_.push(std::shared_ptr<Transformacion>(new TeletransportarEntidad(*this, unaEntidad, p, d)));
}

void Fisicas::teletransportarPosta(Entidad& unaEntidad, Posicion& p, Direccion& d) {
	b2Body* b2Cuerpo = identificables_[unaEntidad.uuid()];
	b2Cuerpo->SetTransform(b2Vec2(p.getX(), p.getY() + 1.0), b2Cuerpo->GetAngle());
	b2Vec2 velocidad = b2Cuerpo->GetLinearVelocity();
	b2Cuerpo->SetLinearVelocity(d.transformar(velocidad));
}

void Fisicas::step() {
    mundo_->Step(CONFIG.TIME_STEP, CONFIG.VELOCITY_ITERATIONS, CONFIG.POSITION_ITERATIONS);	
}

void Fisicas::aplicarTransformaciones() {
	while (!transformaciones_.empty()) {
		std::shared_ptr<Transformacion> t = transformaciones_.front();;
		t->aplicar();
		transformaciones_.pop();
		//No deberia ser necesario con shared pointers
		//delete t;
	}
}
