#include "posicion.h"

Posicion::Posicion(float coordenadaX, float coordenadaY) :
    x_(coordenadaX),
    y_(coordenadaY) {
}

float Posicion::getX() {
    return x_;
}

float Posicion::getY() {
    return y_;
}
