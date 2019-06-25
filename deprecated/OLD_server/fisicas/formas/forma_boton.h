#ifndef __FORMA_BOTON_H__
#define __FORMA_BOTON_H__

#include "forma.h"

class FormaBoton : public Forma {
    public:
    virtual void inicializar(b2Body* unB2Body) override;
    virtual ~FormaBoton();
};

#endif
