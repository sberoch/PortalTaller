#include "forma.h"

Forma::Forma(float unAncho, float unAlto) :
    ancho_(unAncho),
    alto_(unAlto) {
}

float Forma::ancho() {
    return ancho_;
}

float Forma::alto() {
    return alto_;
}

