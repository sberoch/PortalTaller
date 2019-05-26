#include "terreno.h"

#include "../fisicas/fisicas.h"

void Terreno::agregateEn(Fisicas& unasFisicas) {
    unasFisicas.agregar(*this);
}