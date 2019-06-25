#ifndef __PORTAL_DESTINO_H__
#define __PORTAL_DESTINO_H__

#include "portal.h"
#include "../fisicas/posicion.h"
#include "../fisicas/direccion.h"

// Forward declaration
class Jugador;
class Fisicas;
class Posicion;
class Direccion;

class PortalDestino : public Portal {
    private:
    Posicion posicion_;
    Direccion direccion_;    
    public:
    virtual void colisionarContra(Jugador& unJugador) override;
    PortalDestino(Fisicas& unasFisicas, Portal* unDestino, Posicion p, Direccion d);
    virtual void expulsar(Jugador& unJugador) override;
};

#endif