#ifndef __ENTIDAD_H__
#define __ENTIDAD_H__

#include "colisionable.h"

// Forward declaration
class Fisicas;

class Entidad : public Colisionable {
    public:
    virtual void agregateEn(Fisicas& unasFisicas) override;
};

#endif