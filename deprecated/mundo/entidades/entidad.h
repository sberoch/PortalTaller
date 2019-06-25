#ifndef __ENTIDAD_H__
#define __ENTIDAD_H__

#include "../colisionable.h"

class Entidad : public Colisionable {
    public:
    Entidad(Fisicas& unasFisicas);
    virtual ~Entidad();
};

#endif
