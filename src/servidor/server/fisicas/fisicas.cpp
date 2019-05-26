#include "fisicas.h"

#include "../entidades/entidad.h"
#include "../terrenos/terreno.h"

#include "../server_config.h"
Config CONFIG;

Fisicas::Fisicas() : 
    gravedad_(CONFIG.GRAVEDAD_X, CONFIG.GRAVEDAD_Y),
    mundo_(new b2World(gravedad_)) {
}

Fisicas::Fisicas(b2World* unMundo) : mundo_(unMundo) {

}

Fisicas::~Fisicas() {
	
}

void Fisicas::agregar(Identificable& unIdentificable) {
    unIdentificable.agregateEn(*this);
}

void Fisicas::agregar(Entidad& unaEntidad) {
    // Define the dynamic body. We set its position and call the body factory.
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 4.0f);
	b2Body* body = mundo_->CreateBody(&bodyDef);

	// Define another box shape for our dynamic body.
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(0.5f, 1.3f);

	// Define the dynamic body fixture.
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;

	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;

	// Override the default friction.
	fixtureDef.friction = 0.3f;

	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);
}

void Fisicas::agregar(Terreno& unTerreno) {
    b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0.0f, 0.0f);
    b2Body* groundBody = mundo_->CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(1.0f, 1.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);
}

void Fisicas::step() {
    mundo_->Step(CONFIG.TIME_STEP, CONFIG.VELOCITY_ITERATIONS, CONFIG.POSITION_ITERATIONS);
    for (b2Body* b = mundo_->GetBodyList(); b; b = b->GetNext()) {
        b2Vec2 position = b->GetPosition();
	    float32 angle = b->GetAngle();
        printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);
    }
	
}