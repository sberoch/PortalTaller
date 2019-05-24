#ifndef __DISPARO_PORTAL_H__
#define __DISPARO_PORTAL_H__

#include "entidad.h"

// Forward declaration
class Superficie;
class SuperficieAcido;
class SuperficieMetal;

class DisparoPortal : public Entidad {
    public:
    virtual void afectarseCon(Superficie& s) override;
    virtual void afectarseCon(SuperficieAcido& s) override;
    virtual void afectarseCon(SuperficieMetal& s) override;
};

#endif