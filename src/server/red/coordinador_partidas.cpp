#include "coordinador_partidas.h"

CoordinadorPartidas::CoordinadorPartidas(bool& seguirCorriendo) :
    seguirCorriendo_(seguirCorriendo) {
}

void CoordinadorPartidas::cerrar() {
    Thread::cerrar();
}

void CoordinadorPartidas::ejecutar() {
    
}

int CoordinadorPartidas::cantidadPartidas() {
    return partidas_.size();
}

void CoordinadorPartidas::agregarPartida() {
    Partida p;
    partidas_.push_back(p);
}
