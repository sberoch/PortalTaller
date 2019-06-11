#ifndef __ENTIDAD_H__
#define __ENTIDAD_H__

#include "colisionable.h"

// Forward declaration
class Fisicas;
class Posicion;

class Entidad : public Colisionable {
    public:
    virtual void agregateEn(Fisicas& unasFisicas, Posicion& p) override;
    Entidad(Fisicas& unasFisicas);
};

#endif
