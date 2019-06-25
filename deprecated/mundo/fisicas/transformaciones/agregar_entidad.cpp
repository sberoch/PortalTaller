#include "agregar_entidad.h"

#include "../fisicas.h"

AgregarEntidad::AgregarEntidad(Fisicas& unasFisicas, Entidad& unaEntidad, Posicion& unaPosicion, Forma& unaForma) :
    Transformacion(unasFisicas),
    entidad_(unaEntidad),
    posicion_(unaPosicion),
    forma_(unaForma) {
}

AgregarEntidad::~AgregarEntidad() {
}

void AgregarEntidad::aplicar() {
    fisicas_.ejecutarAgregar(entidad_, posicion_, forma_);
}
