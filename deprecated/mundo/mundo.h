#ifndef __MUNDO_H__
#define __MUNDO_H__

#include <map>
#include <cstdint>

#include "fisicas/fisicas.h"

// Forward declaration
class Colisionable;
class Posicion;

class Mundo {
    private:
    Fisicas fisicas_;
    std::map<uint32_t, std::shared_ptr<Colisionable>> bloques_;
    std::map<uint32_t, std::shared_ptr<Colisionable>> entidades_;

    public:
    void agregarBloqueMetalCuadrado(Posicion& posicion);
    void agregarJugador(Posicion& posicion);
    void step();
};

#endif
