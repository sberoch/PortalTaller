#ifndef __FORMA_JUGADOR_H__
#define __FORMA_JUGADOR_H__

#include "forma.h"

class FormaJugador : public Forma {
    public:
    virtual void inicializar(b2Body* unB2Body) override;
    virtual ~FormaJugador();
};

#endif
