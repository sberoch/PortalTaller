#include "coordinador_partidas.h"

#include "../server_config.h"

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
    if (partidas_.size() == CONFIG.MAX_CANTIDAD_PARTIDAS) {
        return;
    }
    Partida p;
    partidas_.push_back(p);
}
