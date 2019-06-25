#ifndef __DISPARO_PORTAL_H__
#define __DISPARO_PORTAL_H__

#include "entidad.h"

// Forward declaration
class Colisionable;
class BloqueMetalCuadrado;

class DisparoPortal : public Entidad {
    public:
    DisparoPortal(Fisicas& unasFisicas);
    virtual void colisionarContra(Colisionable& unColisionable) override;
    virtual void colisionarContra(BloqueMetalCuadrado& b) override;
    virtual ~DisparoPortal();
};

#endif