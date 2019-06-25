#ifndef __FORMA_H__
#define __FORMA_H__

#include "Box2D/Box2D.h"

class Forma {
    public:
    virtual void inicializar(b2Body* unB2Body) = 0;
    void inicializarCaja(b2Body* unB2Body, float sizeX, float sizeY, float densidad, bool esSensor, bool puedeRotar);
    void inicializarCirculo(b2Body* unB2Body, float radio, float densidad, bool esSensor, bool puedeRotar);
    void inicializarTriangulo(b2Body* unB2Body, float sizeX, float sizeY, float densidad, bool esSensor, bool puedeRotar);
    virtual ~Forma();
};

#endif
