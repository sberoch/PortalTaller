#include "agregar_entidad.h"

#include "../fisicas.h"

AgregarEntidad::AgregarEntidad(Fisicas& unasFisicas, Entidad& unaEntidad, Posicion& unaPosicion) :
    Transformacion(unasFisicas),
    entidad_(unaEntidad),
    posicion_(unaPosicion) {
}

void AgregarEntidad::aplicar() {
    fisicas_.agregarPosta(entidad_, posicion_);    
}
