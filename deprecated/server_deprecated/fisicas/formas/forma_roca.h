#ifndef __FORMA_ROCA_H__
#define __FORMA_ROCA_H__

#include "forma.h"

class FormaRoca : public Forma {
    public:
    virtual void inicializar(b2Body* unB2Body) override;
    virtual ~FormaRoca();
};

#endif
