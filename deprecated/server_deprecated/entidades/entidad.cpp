#include "entidad.h"

#include "../fisicas/fisicas.h"
#include "../fisicas/posicion.h"

void Entidad::agregateEn(Fisicas& unasFisicas, Posicion& p) {
    unasFisicas.agregar(*this, p);
}

Entidad::Entidad(Fisicas& unasFisicas) : Colisionable(unasFisicas) {    
}
