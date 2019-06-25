#include "posicion.h"

Posicion::Posicion(float coordenadaX, float coordenadaY) :
    x_(coordenadaX),
    y_(coordenadaY) {
}

float Posicion::x() const {
    return x_;
}

float Posicion::y() const {
    return y_;
}

Posicion Posicion::operator+(const Posicion& otra) {
    return Posicion(x_ + otra.x(), y_ + otra.y());
}
