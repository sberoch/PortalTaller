#include "coordinador_partidas.h"

#include "../server_config.h"

int CoordinadorPartidas::cantidadPartidas() {
    return partidas_.size();
}

void CoordinadorPartidas::agregarPartida() {
    if (partidas_.size() == CONFIG.MAX_CANTIDAD_PARTIDAS) {
        return;
    }
    std::shared_ptr<Partida> partida(std::make_shared<Partida>());
    partidas_.push_back(partida);
}

int CoordinadorPartidas::cantidadDeJugadoresEnPartida(int partida) {
    return partidas_[partida]->cantidadDeJugadores();
}

void CoordinadorPartidas::moverClienteAPartida(std::shared_ptr<Cliente> cliente, int partida) {
    partidas_[partida]->agregar(cliente);
}

std::vector<int> CoordinadorPartidas::jugadoresEnLaPartidaDe(int jugador) {
    
}