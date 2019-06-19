#include "coordinador_partidas.h"
#include <iostream>

void CoordinadorPartidas::agregarPartida(Partida&& unaPartida) {
    std::lock_guard<std::mutex> lck(mtx_);
    partidas_.push_back(std::move(unaPartida));
}

int CoordinadorPartidas::cantidadPartidas() {
    std::lock_guard<std::mutex> lck(mtx_);
    return partidas_.size();
}

int CoordinadorPartidas::cantidadDeJugadoresEn(int partida) {
    std::lock_guard<std::mutex> lck(mtx_);
    return partidas_[partida].cantidadDeJugadores();
}

void CoordinadorPartidas::agregarJugadorAPartida(std::shared_ptr<EscuchadorCliente> cliente, int partida) {
    std::lock_guard<std::mutex> lck(mtx_);
    partidas_[partida].agregar(cliente);
}

void CoordinadorPartidas::iniciar(int partidaSeleccionada) {
    std::lock_guard<std::mutex> lck(mtx_);
    partidas_[partidaSeleccionada].iniciar();
}
