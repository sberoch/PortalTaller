#include "jugador.h"

#include "../colisionable.h"

Jugador::Jugador(Fisicas& unasFisicas) :
    Entidad(unasFisicas) {
}

void Jugador::colisionarContra(Colisionable& otro) {
    otro.colisionarContra(*this);
}

Jugador::~Jugador() {    
}
