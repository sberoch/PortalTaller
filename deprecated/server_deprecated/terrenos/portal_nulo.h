#ifndef __PORTAL_NULO_H__
#define __PORTAL_NULO_H__

#include "portal.h"

// Forward declaration
class Jugador;

class PortalNulo : public Portal {
    public:
    virtual void colisionarContra(Jugador& unJugador) override;
    PortalNulo(Fisicas& unasFisicas);
};

#endif