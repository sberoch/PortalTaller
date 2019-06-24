#include "coordinador_partidas.h"

CoordinadorPartidas::CoordinadorPartidas(bool& seguirCorriendo) :
    seguirCorriendo_(seguirCorriendo) {
}

void CoordinadorPartidas::cerrar() {
    Thread::cerrar();
}

void CoordinadorPartidas::ejecutar() {
    
}