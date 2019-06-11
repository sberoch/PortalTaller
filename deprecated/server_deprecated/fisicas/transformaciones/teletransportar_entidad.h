#ifndef __TELETRANSPORTAR_ENTIDAD_H__
#define __TELETRANSPORTAR_ENTIDAD_H__

#include "transformacion.h"

// Forward declaration
class Entidad;
class Posicion;
class Direccion;

class TeletransportarEntidad : public Transformacion {
    private:
    Entidad& entidad_;
    Posicion& posicion_;
    Direccion& direccion_;
    
    public:
    TeletransportarEntidad(Fisicas& unasFisicas, Entidad& unaEntidad, Posicion& p, Direccion& d);
    virtual void aplicar() override;
};

#endif
