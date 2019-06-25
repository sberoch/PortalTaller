#include "agregar_bloque_metal_cuadrado.h"

#include "../fisicas.h"

AgregarBloqueMetalCuadrado::AgregarBloqueMetalCuadrado(Fisicas& unasFisicas, BloqueMetalCuadrado& b, Posicion& unaPosicion) :
    Transformacion(unasFisicas),
    bloque_(b),
    posicion_(unaPosicion) {
}

void AgregarBloqueMetalCuadrado::aplicar() {
    fisicas_.agregarPosta(bloque_, posicion_);    
}
