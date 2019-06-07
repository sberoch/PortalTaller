#ifndef __DIRECCION_H__
#define __DIRECCION_H__

#include "Box2D/Box2D.h"

// Forward declaration
class Rotacion;

class Direccion {
    private:
    float x_;
    float y_;

    public:
    Direccion(float x, float y);
    Direccion copiar();
    b2Vec2 transformar(b2Vec2& unaVelocidad);
    void rotar(Rotacion& r);
};

#endif
