#include "destruir_entidad.h"

DestruirEntidad::DestruirEntidad(Fisicas& unasFisicas, Entidad& unaEntidad) :
    Transformacion(unasFisicas),
    entidad_(unaEntidad) {

}

void DestruirEntidad::aplicar() {
    fisicas_.destruirPosta(entidad_);
}
