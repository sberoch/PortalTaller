#include "portal_destino.h"

#include "../fisicas/posicion.h"
#include "../fisicas/direccion.h"

PortalDestino::PortalDestino(Fisicas& unasFisicas, Portal* unDestino, Posicion p, Direccion d):
    Portal(unasFisicas, unDestino),
    posicion_(p),
    direccion_(d) {
}

void PortalDestino::colisionarContra(Jugador& unJugador) {
    destino_->expulsar(unJugador);
    
}

void PortalDestino::expulsar(Jugador& unJugador) {
    fisicas_.teletransportar(unJugador, posicion_, direccion_);
}