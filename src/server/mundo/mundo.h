#ifndef __MUNDO_H__
#define __MUNDO_H__

#include <map>
#include <queue>

#include "fisicas/fisicas.h"

// Forward declaration
class Colisionable;
class Posicion;
class Velocidad;
class Rotacion;
class Evento;

class Mundo {
    private:
    Fisicas fisicas_;
    std::map<int, std::shared_ptr<Colisionable>> bloques_;
    std::map<int, std::shared_ptr<Entidad>> entidades_;
    std::queue<std::shared_ptr<Evento>> eventos_;

    public:
    void agregarBloqueMetalCuadrado(Posicion& posicion);
    void agregarBloqueMetalTriangular(Posicion& posicion, Rotacion& r);
    void agregarJugador(Posicion& posicion);
    void moverJugador(int uuidDelJugador, Velocidad& v);
    void step();
    // Testing
    Fisicas* getFisicas() {return &fisicas_;}
};

#endif
