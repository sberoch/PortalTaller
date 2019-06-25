#ifndef __FORMA_BLOQUE_H__
#define __FORMA_BLOQUE_H__

#include "forma.h"

#include "Box2D/Box2D.h"

class FormaBloque : public Forma {
    public:
    virtual void inicializar(b2Body* unB2Body) override;
    virtual ~FormaBloque();
};

#endif
