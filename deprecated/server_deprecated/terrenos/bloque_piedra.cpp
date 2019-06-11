#include "bloque_piedra.h"

#include "../entidades/colisionable.h"

void BloquePiedra::colisionarContra(Colisionable& unColisionable) {
    unColisionable.colisionarContra(*this);
}