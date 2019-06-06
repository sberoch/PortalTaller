#include "velocidad.h"

Velocidad::Velocidad(float x, float y) :
    coordenadaX_(x),
    coordenadaY_(y) {
}

Velocidad::~Velocidad() {
}

float Velocidad::x() {
    return coordenadaX_;
}

float Velocidad::y() {
    return coordenadaY_;
}
