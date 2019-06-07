#include "direccion.h"
#include "rotacion.h"

Direccion::Direccion(float x, float y) :
    x_(x),
    y_(y) {
}

Direccion Direccion::copiar() {
    Direccion tmp(x_, y_);
    return tmp;
}

b2Vec2 Direccion::transformar(b2Vec2& unaVelocidad) {
    float norma = unaVelocidad.Length();
    return b2Vec2(x_ * norma, y_ * norma);
}

void Direccion::rotar(Rotacion& r) {
    int a = 0;
    int b = -1;
    int c = 1;
    int d = 0;
    
    for (size_t i = 0; i < r.anguloGrados() / 90; i++) {
        x_ = (a*x_ + b*y_);
        y_ = (c*x_ + d*y_);
    } 
}
