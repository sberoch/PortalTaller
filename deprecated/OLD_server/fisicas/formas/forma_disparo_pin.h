#ifndef __FORMA_DISPARO_PIN_H__
#define __FORMA_DISPARO_PIN_H__

#include "forma.h"

class FormaDisparoPin : public Forma {
    public:
    virtual void inicializar(b2Body* unB2Body) override;
    virtual ~FormaDisparoPin();
};

#endif
