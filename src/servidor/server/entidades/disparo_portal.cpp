#include "disparo_portal.h"

#include "colisionable.h"
#include "../terrenos/bloque_metal_cuadrado.h"

void DisparoPortal::colisionarContra(Colisionable& unColisionable) {
    unColisionable.colisionarContra(*this);
}

void DisparoPortal::colisionarContra(BloqueMetalCuadrado& b) {
    
}