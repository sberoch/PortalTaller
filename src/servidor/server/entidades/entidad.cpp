#include "entidad.h"

#include "../fisicas/fisicas.h"

#include <iostream>

void Entidad::agregateEn(Fisicas& unasFisicas) {
    unasFisicas.agregar(*this);
}
