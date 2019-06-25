#ifndef __AGREGAR_BLOQUE_METAL_CUADRADO_H__
#define __AGREGAR_BLOQUE_METAL_CUADRADO_H__

#include "transformacion.h"

// Forward declaration
class Fisicas;
class BloqueMetalCuadrado;
class Posicion;

class AgregarBloqueMetalCuadrado : public Transformacion {
    private:
    BloqueMetalCuadrado& bloque_;
    Posicion& posicion_;

    public:
    AgregarBloqueMetalCuadrado(Fisicas& unasFisicas, BloqueMetalCuadrado& b, Posicion& unaPosicion);
    virtual void aplicar() override;
};

#endif
