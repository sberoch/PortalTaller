#include "coordinador_partidas.h"

#include "../server_config.h"

CoordinadorPartidas::CoordinadorPartidas(bool& seguirCorriendo) :
    seguirCorriendo_(seguirCorriendo) {
}

int CoordinadorPartidas::cantidadPartidas() {
    return partidas_.size();
}

void CoordinadorPartidas::agregarPartida() {
    if (partidas_.size() == CONFIG.MAX_CANTIDAD_PARTIDAS) {
        return;
    }
    std::shared_ptr<Partida> partida(std::make_shared<Partida>(seguirCorriendo_));
    partidas_.push_back(partida);
}

int CoordinadorPartidas::cantidadDeJugadoresEnPartida(int partida) {
    return partidas_[partida]->cantidadDeJugadores();
}

void CoordinadorPartidas::moverClienteAPartida(std::shared_ptr<Cliente> cliente, int partida) {
    partidas_[partida]->agregar(cliente);
}

std::vector<int> CoordinadorPartidas::jugadoresEnLaPartida(int partida) {
   return partidas_[partida]->jugadores();
}

void CoordinadorPartidas::iniciarPartida(int partida) {
    partidas_[partida]->iniciar();
}

CoordinadorPartidas::~CoordinadorPartidas() {
    for (auto& partida : partidas_) {
        partida->cerrar();
    }
}