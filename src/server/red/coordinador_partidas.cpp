#include "coordinador_partidas.h"
#include <iostream>

void CoordinadorPartidas::agregarPartida(Partida&& unaPartida) {
    std::lock_guard<std::mutex> lck(mtx_);
    partidas_.push_back(std::move(unaPartida));
}

int CoordinadorPartidas::cantidadPartidas() {
    return partidas_.size();
}

int CoordinadorPartidas::cantidadDeJugadoresEn(int partida) {
    return partidas_[partida].cantidadDeJugadores();
}

void CoordinadorPartidas::agregarJugadorAPartida(std::shared_ptr<EscuchadorCliente> cliente, int partida) {
    partidas_[partida].agregar(cliente);
}

void CoordinadorPartidas::iniciar(int partidaSeleccionada) {
    partidas_[partidaSeleccionada].iniciar();
}