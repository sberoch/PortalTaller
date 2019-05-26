#include "jugador.h"

#include "colisionable.h"

Jugador::Jugador() {}

Jugador::~Jugador() {}

void Jugador::colisionarContra(Colisionable& unColisionable) {
    unColisionable.colisionarContra(*this);
}