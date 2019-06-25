#ifndef __SUPERFICIE_H__
#define __SUPERFICIE_H__

#include "../colisionable.h"

class Superficie : public Colisionable {
    public:
    Superficie(Fisicas& unasFisicas);
    virtual ~Superficie();
};

#endif