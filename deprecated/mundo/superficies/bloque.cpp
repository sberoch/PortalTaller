#include "bloque.h"

Bloque::Bloque(Fisicas& unasFisicas) :
    Colisionable(unasFisicas) {
}

Bloque::~Bloque() {
}

void Bloque::colisionarContra(Colisionable& otro) {
    otro.colisionarContra(*this);
}
