#ifndef __TERRENO_H__
#define __TERRENO_H__

#include "../entidades/colisionable.h"

// Forward declaration
class Fisicas;

class Terreno : public Colisionable {
public:
    virtual void agregateEn(Fisicas& unasFisicas) override;
};

#endif