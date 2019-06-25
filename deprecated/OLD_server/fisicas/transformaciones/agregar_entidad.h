#ifndef __AGREGAR_ENTIDAD_H__
#define __AGREGAR_ENTIDAD_H__

#include "transformacion.h"

// Forward declaration
class Fisicas;
class Entidad;
class Posicion;

class AgregarEntidad : public Transformacion {
    private:
    Entidad& entidad_;
    Posicion& posicion_;

    public:
    AgregarEntidad(Fisicas& unasFisicas, Entidad& unaEntidad, Posicion& unaPosicion);
    virtual void aplicar() override;
};

#endif 
