#include "direccion.h"

Direccion::Direccion(float x, float y) :
    x_(x),
    y_(y) {
}

b2Vec2 Direccion::transformar(b2Vec2& unaVelocidad) {
    float norma = unaVelocidad.Length();
    return b2Vec2(x_ * norma, y_ * norma);
}
