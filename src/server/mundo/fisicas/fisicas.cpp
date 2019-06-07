#include "fisicas.h"

#include <vector>

#include "../../server_config.h"

#include "../superficies/superficie.h"
#include "../superficies/bloque.h"
//#include "../entidades/bloque_metal_cuadrado.h"

#include "../entidades/entidad.h"

#include "movimiento/posicion.h"
#include "movimiento/velocidad.h"
#include "movimiento/rotacion.h"
#include "formas/forma.h"

#include "transformaciones/transformacion.h"
#include "transformaciones/agregar_entidad.h"
#include "transformaciones/cambiar_velocidad.h"

//#define PI 3.14159265358979323846f

Fisicas::Fisicas() :
    gravedad_(CONFIG.GRAVEDAD_X, CONFIG.GRAVEDAD_Y),
    mundoBox2D_(new b2World(gravedad_)) {
    mundoBox2D_->SetContactListener(&contactListener_);
}

Fisicas::~Fisicas() {
    //delete mundoBox2D_;
}

void Fisicas::step() {
    mundoBox2D_->Step(CONFIG.TIME_STEP, CONFIG.VELOCITY_ITERATIONS, CONFIG.POSITION_ITERATIONS);
    aplicarTransformaciones();    
}

void Fisicas::agregarBloqueRectangular(Bloque& unBloque, Posicion& unaPosicion, Forma& unaForma) {
    
    b2BodyDef b2CuerpoDef;
    b2CuerpoDef.type = b2_staticBody;
    b2CuerpoDef.position.Set(unaPosicion.x(), unaPosicion.y());
	b2CuerpoDef.userData = &unBloque;
    b2Body* b2Cuerpo = mundoBox2D_->CreateBody(&b2CuerpoDef);
    
    b2PolygonShape b2FormaCaja;
	b2FormaCaja.SetAsBox(unaForma.ancho(), unaForma.alto());
	b2FixtureDef b2Caracteristicas;
	b2Caracteristicas.shape = &b2FormaCaja;
	b2Cuerpo->CreateFixture(&b2Caracteristicas);

    colisionables_[unBloque.uuid()] = b2Cuerpo;
}

void Fisicas::agregarBloqueTriangular(Bloque& unBloque, Posicion& unaPosicion, Forma& unaForma, Rotacion& r) {
    
    b2BodyDef b2CuerpoDef;
    b2CuerpoDef.type = b2_staticBody;
    b2CuerpoDef.position.Set(unaPosicion.x(), unaPosicion.y());
	b2CuerpoDef.userData = &unBloque;
    b2Body* b2Cuerpo = mundoBox2D_->CreateBody(&b2CuerpoDef);
    
    b2Vec2 vertices[3];
    vertices[0].Set(0.0f, 0.0f);
    vertices[1].Set(2 * unaForma.ancho(), 0.0f);
    vertices[2].Set(0.0f, 2 * unaForma.alto());

    std::vector<b2Vec2> deltas;
    deltas.push_back(b2Vec2(-1.0f, -1.0f));
    deltas.push_back(b2Vec2(1.0f, -1.0f));
    deltas.push_back(b2Vec2(1.0f, 1.0f));
    deltas.push_back(b2Vec2(-1.0f, 1.0f));

    int indice_delta = 0;

    for (size_t i = 0; i < r.anguloGrados() / 90; i++) {
        indice_delta++;
    }    
    
    int32 count = 3;
    b2PolygonShape b2Triangulo;
    b2Triangulo.Set(vertices, count);

	b2FixtureDef b2Caracteristicas;
	b2Caracteristicas.shape = &b2Triangulo;
	b2Cuerpo->CreateFixture(&b2Caracteristicas);
    b2Cuerpo->SetTransform(b2Cuerpo->GetWorldCenter() + deltas[indice_delta], r.anguloRadianes());

    colisionables_[unBloque.uuid()] = b2Cuerpo;
}

void Fisicas::agregarSuperficie(Superficie& unaSuperficie, Posicion& unaPosicion, Forma& unaForma, Rotacion& r) {
    b2BodyDef b2CuerpoDef;
    b2CuerpoDef.type = b2_staticBody;
    b2CuerpoDef.position.Set(unaPosicion.x(), unaPosicion.y());
	b2CuerpoDef.userData = &unaSuperficie;
    b2Body* b2Cuerpo = mundoBox2D_->CreateBody(&b2CuerpoDef);
    
    b2PolygonShape b2FormaCaja;
	b2FormaCaja.SetAsBox(unaForma.ancho(), unaForma.alto());
	b2FixtureDef b2Caracteristicas;
	b2Caracteristicas.shape = &b2FormaCaja;
    b2Caracteristicas.isSensor = true;
	b2Cuerpo->CreateFixture(&b2Caracteristicas);

    b2Cuerpo->SetTransform(b2Cuerpo->GetPosition(), r.anguloRadianes());

    colisionables_[unaSuperficie.uuid()] = b2Cuerpo;
}

void Fisicas::agregarEntidad(Entidad& unaEntidad, Posicion& unaPosicion, Forma& unaForma) {
    transformaciones_.push(std::shared_ptr<Transformacion>(new AgregarEntidad(*this, unaEntidad, unaPosicion, unaForma)));
}

void Fisicas::ejecutarAgregar(Entidad& unaEntidad, Posicion& unaPosicion, Forma& unaForma) {
    b2BodyDef b2CuerpoDef;
    // Para simular mejor el movimiento
	b2CuerpoDef.bullet = true;
	b2CuerpoDef.type = b2_dynamicBody;
	b2CuerpoDef.position.Set(unaPosicion.x(), unaPosicion.y());
	b2CuerpoDef.userData = &unaEntidad;
	b2Body* b2Cuerpo = mundoBox2D_->CreateBody(&b2CuerpoDef);

    b2PolygonShape b2FormaCaja;
	b2FormaCaja.SetAsBox(unaForma.ancho(), unaForma.alto());
	b2FixtureDef b2Caracteristicas;
	b2Caracteristicas.shape = &b2FormaCaja;
	b2Cuerpo->CreateFixture(&b2Caracteristicas);
	
	colisionables_[unaEntidad.uuid()] = b2Cuerpo;
}

void Fisicas::cambiarVelocidad(Entidad& unaEntidad, Velocidad& unaVelocidad) {
    transformaciones_.push(std::shared_ptr<Transformacion>(new CambiarVelocidad(*this, unaEntidad, unaVelocidad)));
}

void Fisicas::ejecutarCambiarVelocidad(Entidad& unaEntidad, Velocidad& unaVelocidad) {
    b2Body* b2Entidad = colisionables_[unaEntidad.uuid()];
    b2Vec2 nuevaVelocidad = b2Vec2(unaVelocidad.x(), unaVelocidad.y());
    b2Entidad->SetLinearVelocity(nuevaVelocidad);
}

void Fisicas::aplicarTransformaciones() {
    while (!transformaciones_.empty()) {
		std::shared_ptr<Transformacion> t = transformaciones_.front();
		t->aplicar();
		transformaciones_.pop();
    }
}
