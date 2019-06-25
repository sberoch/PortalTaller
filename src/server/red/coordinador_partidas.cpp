#include "coordinador_partidas.h"

#include "../server_config.h"

CoordinadorPartidas::CoordinadorPartidas(bool& seguirCorriendo) :
    seguirCorriendo_(seguirCorriendo) {
}

void CoordinadorPartidas::cerrar() {
    eventosEntrantes_.detener();
    Thread::cerrar();
}

void CoordinadorPartidas::manejar(Evento& evento) {
    evento.actualizar(*this);
}

void CoordinadorPartidas::ejecutar() {
    bool obtenido;
    std::shared_ptr<Evento> evento;
    while(seguirCorriendo_ && (obtenido = eventosEntrantes_.get(evento))) {
        manejar(*evento);
    }    
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
