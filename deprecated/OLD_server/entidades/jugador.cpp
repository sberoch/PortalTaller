#include "jugador.h"

#include <memory>

#include "colisionable.h"
#include "../fisicas/formas/forma_jugador.h"

Jugador::Jugador(Fisicas& unasFisicas) : Entidad(unasFisicas) {
    forma_ = std::shared_ptr<Forma>(new FormaJugador());
}

Jugador::~Jugador() {}

void Jugador::colisionarContra(Colisionable& unColisionable) {
    unColisionable.colisionarContra(*this);
}
