#ifndef __FISICAS_H__
#define __FISICAS_H__

#include "Box2D/Box2D.h"

//Forward declaration
class Entidad;
class Terreno;
class Identificable;

class Fisicas {
    private:
    b2Vec2 gravedad_;
    b2World* mundo_;

    public:
    Fisicas();
    explicit Fisicas(b2World* unMundo);
    ~Fisicas();
    void agregar(Identificable& unIdentificable);
    void agregar(Entidad& unaEntidad);
    void agregar(Terreno& unTerreno);
    void step();
};

#endif