#include "fisicas.h"

#include "../../server_config.h"

#include "../superficies/superficie.h"
#include "../superficies/bloque.h"
//#include "../entidades/bloque_metal_cuadrado.h"

#include "../entidades/entidad.h"

#include "movimiento/posicion.h"
#include "formas/forma.h"

#include "transformaciones/transformacion.h"
#include "transformaciones/agregar_entidad.h"

#include "transformaciones/agregar_entidad.h"

//#define PI 3.14159265358979323846f

Fisicas::Fisicas() :
    gravedad_(CONFIG.GRAVEDAD_X, CONFIG.GRAVEDAD_Y),
    mundoBox2D_(new b2World(gravedad_)) {
    mundoBox2D_->SetContactListener(&contactListener_);
}

Fisicas::~Fisicas() {
    delete mundoBox2D_;
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

void Fisicas::agregarSuperficie(Superficie& unaSuperficie, Posicion& unaPosicion, Forma& unaForma) {
    b2BodyDef b2CuerpoDef;
    b2CuerpoDef.type = b2_staticBody;
    b2CuerpoDef.position.Set(unaPosicion.x(), unaPosicion.y());
	b2CuerpoDef.userData = &unaSuperficie;
    b2Body* b2Cuerpo = mundoBox2D_->CreateBody(&b2CuerpoDef);
    
    b2Cuerpo->SetFixedRotation(true);

    b2PolygonShape b2FormaCaja;
	b2FormaCaja.SetAsBox(unaForma.ancho(), unaForma.alto());
	b2FixtureDef b2Caracteristicas;
	b2Caracteristicas.shape = &b2FormaCaja;
    b2Caracteristicas.isSensor = true;
	b2Cuerpo->CreateFixture(&b2Caracteristicas);

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

void Fisicas::aplicarTransformaciones() {
    while (!transformaciones_.empty()) {
		std::shared_ptr<Transformacion> t = transformaciones_.front();
		t->aplicar();
		transformaciones_.pop();
    }
}
