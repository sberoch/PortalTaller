#ifndef __DIRECCION_H__
#define __DIRECCION_H__

#include "Box2D/Box2D.h"

class Direccion {
    private:
    float x_;
    float y_;

    public:
    Direccion(float x, float y);
    b2Vec2 transformar(b2Vec2& unaVelocidad);
};

#endif
