#ifndef __MUNDO_H__
#define __MUNDO_H__

#include <map>
#include <queue>

#include "fisicas/fisicas.h"

// Forward declaration
class Colisionable;
class Posicion;
class Evento;

class Mundo {
    private:
    Fisicas fisicas_;
    std::map<int, std::shared_ptr<Colisionable>> bloques_;
    std::map<int, std::shared_ptr<Colisionable>> entidades_;
    std::queue<std::shared_ptr<Evento>> eventos_;

    public:
    void agregarBloqueMetalCuadrado(Posicion& posicion);
    void agregarJugador(Posicion& posicion);
    void step();
};

#endif
