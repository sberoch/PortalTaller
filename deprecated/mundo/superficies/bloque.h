#ifndef __BLOQUE_H__
#define __BLOQUE_H__

#include "../colisionable.h"

class Bloque : public Colisionable {
    public:
    Bloque(Fisicas& unasFisicas);
    virtual ~Bloque();
    virtual void colisionarContra(Colisionable& otro) override;
};

#endif
