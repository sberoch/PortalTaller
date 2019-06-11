#ifndef __BLOQUE_METAL_CUADRADO_H__
#define __BLOQUE_METAL_CUADRADO_H__

#include "terreno.h"

// Forward declaration
class Colisionable;
class DisparoPortal;

class BloqueMetalCuadrado : public Terreno {
  
    public:
    virtual void colisionarContra(Colisionable& unColisionable) override;
    virtual void colisionarContra(DisparoPortal& d) override;
    BloqueMetalCuadrado(Fisicas& unasFisicas);
};

#endif
