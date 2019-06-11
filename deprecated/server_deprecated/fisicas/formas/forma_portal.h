#ifndef __FORMA_PORTAL_H__
#define __FORMA_PORTAL_H__

#include "forma.h"

#include "Box2D/Box2D.h"

class FormaPortal : public Forma {
    public:
    virtual void inicializar(b2Body* unB2Body) override;
    virtual ~FormaPortal();
};

#endif