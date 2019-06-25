#include "contactos.h"

#include "../colisionable.h"

ContactListener::ContactListener() {
}

ContactListener::~ContactListener() {    
}

void ContactListener::BeginContact(b2Contact* contact) {
    Colisionable* colisionableA = contact->GetFixtureA()->GetBody()->GetUserData();
    Colisionable* colisionableB = contact->GetFixtureB()->GetBody()->GetUserData();
    
    if(!colisionableA || !colisionableB) {
        return;
    }
    
    colisionableA->colisionarContra(*colisionableB);
    colisionableB->colisionarContra(*colisionableA);
}

void ContactListener::EndContact(b2Contact* contact) {
}

void ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {

}

void ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {
    
}
