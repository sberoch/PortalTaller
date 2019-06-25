#include "superficie_metal.h"

SuperficieMetal::SuperficieMetal(Fisicas& unasFisicas, Direccion& unaDireccion) :
    Superficie(unasFisicas),
    direccion_(unaDireccion.copiar()) {
}

SuperficieMetal::~SuperficieMetal() {
}

void SuperficieMetal::colisionarContra(Colisionable& unColisionable) {
    unColisionable.colisionarContra(*this);
}
