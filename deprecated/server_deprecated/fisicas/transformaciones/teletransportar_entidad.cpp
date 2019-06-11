#include "teletransportar_entidad.h"

TeletransportarEntidad::TeletransportarEntidad(Fisicas& unasFisicas, Entidad& unaEntidad, Posicion& p, Direccion& d) :
    Transformacion(unasFisicas),
    entidad_(unaEntidad),
    posicion_(p),
    direccion_(d) {

}

void TeletransportarEntidad::aplicar() {
    fisicas_.teletransportarPosta(entidad_, posicion_, direccion_);
}
