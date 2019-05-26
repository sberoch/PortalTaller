#include "bloque_metal_cuadrado.h"

#include "../entidades/colisionable.h"
#include "../entidades/disparo_portal.h"

void BloqueMetalCuadrado::colisionarContra(Colisionable& unColisionable) {
    unColisionable.colisionarContra(*this);
}

void BloqueMetalCuadrado::colisionarContra(DisparoPortal& d) {
}