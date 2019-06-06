#include "rotacion.h"

#define DECIMAL_A_RADIANES 0.0174533f

Rotacion::Rotacion(size_t unAnguloEnGrados) :
    angulo_(unAnguloEnGrados) {
}

Rotacion::~Rotacion() {
}

float Rotacion::anguloRadianes() {
    return angulo_ * DECIMAL_A_RADIANES;
}

size_t Rotacion::anguloGrados() {
    return angulo_;
}
