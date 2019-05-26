#ifndef __BLOQUE_PIEDRA_H__
#define __BLOQUE_PIEDRA_H__

#include "terreno.h"

// Forward Declaration
class Colisionable;

class BloquePiedra : public Terreno {
    public:
    virtual void colisionarContra(Colisionable& unColisionable) override;
};

#endif