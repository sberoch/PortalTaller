#ifndef __FISICAS_H__
#define __FISICAS_H__

#include <map>
#include <queue>
#include <memory>

#include "Box2D/Box2D.h"

#include "contactos.h"

// Forward declaration
class Forma;
class Bloque;
class Superficie;

class Entidad;
//class BloqueMetalCuadrado;
//class BloquePiedra;
//class Jugador;
//class DisparoPortal;
class Posicion;
class Transformacion;

class Fisicas {
    private:
    b2Vec2 gravedad_;
    b2World* mundoBox2D_;
    ContactListener contactListener_;
    std::map<int, b2Body*> colisionables_;
    std::queue<std::shared_ptr<Transformacion>> transformaciones_;

    public:
    Fisicas();
    ~Fisicas();
    void agregarBloqueRectangular(Bloque& unBloque, Posicion& unaPosicion, Forma& forma);
    void agregarSuperficie(Superficie& superficie, Posicion& posicion, Forma& forma);
    void agregarEntidad(Entidad& entidad, Posicion& posicion, Forma& forma);
    void ejecutarAgregar(Entidad& entidad, Posicion& posicion, Forma& forma);
    //void agregarBloqueMetalCuadrado(BloqueMetalCuadrado& bloque, Posicion& posicion);
    //void agregarBloquePiedra(BloquePiedra& bloque, Posicion& posicion);
    //void agregarJugador(Jugador& jugador, Posicion& posicion);
    //void agregarDisparoPortal(DisparoPortal& disparo, Posicion& posicion);
    
    void aplicarTransformaciones();
    void step();

    // Testing
    void setMundo(b2World* mundoCreado) {mundoBox2D_ = mundoCreado; mundoBox2D_->SetContactListener(&contactListener_);}
};

#endif
