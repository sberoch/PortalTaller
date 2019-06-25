#ifndef __FORMA_BOLA_ENERGIA_H__
#define __FORMA_BOLA_ENERGIA_H__

#include "forma.h"

class FormaBolaEnergia : public Forma {
    public:
    virtual void inicializar(b2Body* unB2Body) override;
    virtual ~FormaBolaEnergia();
};

#endif
