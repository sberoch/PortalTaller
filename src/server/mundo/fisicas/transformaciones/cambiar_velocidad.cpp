#include "cambiar_velocidad.h"

#include "../fisicas.h"

CambiarVelocidad::CambiarVelocidad(Fisicas& unasFisicas, Entidad& unaEntidad, Velocidad& unaVelocidad) :
    Transformacion(unasFisicas),
    entidad_(unaEntidad),
    velocidad_(unaVelocidad) {
}

CambiarVelocidad::~CambiarVelocidad() {
}

void CambiarVelocidad::aplicar() {
    fisicas_.ejecutarCambiarVelocidad(entidad_, velocidad_);
}

