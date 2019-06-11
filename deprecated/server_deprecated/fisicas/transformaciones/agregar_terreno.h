#ifndef __AGREGAR_TERRENO_H__
#define __AGREGAR_TERRENO_H__

#include "transformacion.h"

// Forward declaration
class Fisicas;
class Terreno;
class Posicion;

class AgregarTerreno : public Transformacion {
    private:
    Terreno& terreno_;
    Posicion& posicion_;

    public:
    AgregarTerreno(Fisicas& unasFisicas, Terreno& unTerreno, Posicion& unaPosicion);
    virtual void aplicar() override;
};

#endif
