#include "forma.h"

void Forma::inicializarCaja(b2Body* unB2Body, float sizeX, float sizeY, float densidad, bool esSensor, bool puedeRotar) {
    b2PolygonShape formaCaja;
	formaCaja.SetAsBox(sizeX, sizeY);
	b2FixtureDef caracteristicas;
	caracteristicas.shape = &formaCaja;
	caracteristicas.density = densidad;
    caracteristicas.isSensor = esSensor;
	unB2Body->SetFixedRotation(!puedeRotar);
	unB2Body->CreateFixture(&caracteristicas);
}

void Forma::inicializarCirculo(b2Body* unB2Body, float radio, float densidad, bool esSensor, bool puedeRotar) {
    b2CircleShape formaCirculo;
    formaCirculo.m_radius = radio;
    b2FixtureDef caracteristicas;
	caracteristicas.shape = &formaCirculo;
	caracteristicas.density = densidad;
    caracteristicas.isSensor = esSensor;
	unB2Body->SetFixedRotation(!puedeRotar);
	unB2Body->CreateFixture(&caracteristicas);
}

void Forma::inicializarTriangulo(b2Body* unB2Body, float sizeX, float sizeY, float densidad, bool esSensor, bool puedeRotar) {
	b2Vec2 vertices[3];
	vertices[0].Set(0.0f, 0.0f);
	vertices[1].Set(sizeX, 0.0f);
	vertices[2].Set(0.0f, sizeY);
	int32 nVertices = 3;
	b2PolygonShape formaTriangulo;
	formaTriangulo.Set(vertices, nVertices);
	b2FixtureDef caracteristicas;
	caracteristicas.shape = &formaTriangulo;
	caracteristicas.density = densidad;
    caracteristicas.isSensor = esSensor;
	unB2Body->SetFixedRotation(!puedeRotar);
	unB2Body->CreateFixture(&caracteristicas);
}

Forma::~Forma() {
}
