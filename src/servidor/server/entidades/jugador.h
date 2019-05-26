#ifndef __JUGADOR_H__
#define __JUGADOR_H__

#include "entidad.h"

// Forward declaration
class Colisionable;

class Jugador : public Entidad {
public:
    Jugador();
    virtual ~Jugador();
    virtual void colisionarContra(Colisionable& unColisionable) override;
};

#endif