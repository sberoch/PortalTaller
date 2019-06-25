#ifndef __PORTAL_H__
#define __PORTAL_H__

#include "terreno.h"

// Forward declaration
class Colisionable;
class Jugador;

class Portal : public Terreno {
    protected:
    Portal* destino_;
    
    public:
    virtual void colisionarContra(Colisionable& unColisionable) override;
    virtual void colisionarContra(Jugador& unJugador) override;

    Portal(Fisicas& unasFisicas, Portal* unDestino);

    void setDestino(Portal* unDestino);

    virtual void expulsar(Jugador& unJugador);
};

#endif