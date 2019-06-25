#include "forma.h"

Forma::Forma(float unAncho, float unAlto, float unaRotacion) :
    ancho_(unAncho),
    alto_(unAlto),
    rotacion_(unaRotacion) {

}

float Forma::ancho() {
    return ancho_;
}

float Forma::alto() {
    return alto_;
}

float Forma::rotacion() {
    return rotacion_;
}
