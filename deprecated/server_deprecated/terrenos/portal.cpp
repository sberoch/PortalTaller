#include "portal.h"
#include "portal_destino.h"

#include "../entidades/colisionable.h"
#include "../entidades/jugador.h"
#include "../fisicas/formas/forma_portal.h"

void Portal::colisionarContra(Colisionable& unColisionable) {
    unColisionable.colisionarContra(*this);
    
}

void Portal::colisionarContra(Jugador& unJugador) {
    destino_->colisionarContra(unJugador);
}

Portal::Portal(Fisicas& unasFisicas, Portal* unDestino) :
    Terreno(unasFisicas),
    destino_(unDestino) {
    forma_ = std::shared_ptr<Forma>(new FormaPortal());
}

void Portal::setDestino(Portal* unDestino) {
    destino_ = unDestino;
}

void Portal::expulsar(Jugador& unJugador) {
    
}