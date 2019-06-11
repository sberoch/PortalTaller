#ifndef __FORMA_TRIANGULO_H__
#define __FORMA_TRIANGULO_H__

#include "forma.h"

class FormaTriangulo : public Forma {
    public:
    virtual void inicializar(b2Body* unB2Body) override;
    virtual ~FormaTriangulo();
}

#endif