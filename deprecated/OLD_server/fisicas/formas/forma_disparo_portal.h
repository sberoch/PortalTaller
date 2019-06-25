#ifndef __FORMA_DISPARO_PORTAL_H__
#define __FORMA_DISPARO_PORTAL_H__

#include "forma.h"

class FormaDisparoPortal : public Forma {
    public:
    virtual void inicializar(b2Body* unB2Body) override;
    virtual ~FormaDisparoPortal();
};

#endif
