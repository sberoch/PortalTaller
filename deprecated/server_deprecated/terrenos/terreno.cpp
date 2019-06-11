#include "terreno.h"

#include "../fisicas/fisicas.h"

void Terreno::agregateEn(Fisicas& unasFisicas, Posicion& p) {
    unasFisicas.agregar(*this, p);
}

Terreno::Terreno(Fisicas& unasFisicas) : Colisionable(unasFisicas) {}