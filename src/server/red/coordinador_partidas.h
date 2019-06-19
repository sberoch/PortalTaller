#ifndef __COORDINADOR_PARTIDAS_H__
#define __COORDINADOR_PARTIDAS_H__

#include <vector>
#include <mutex>
#include <memory>
#include "escuchador_cliente.h"

#include "partida.h"

class CoordinadorPartidas {
    private:
    std::vector<Partida> partidas_;
    std::mutex mtx_;

    public:
    void agregarPartida(Partida&& unaPartida);
    int cantidadPartidas();
    int cantidadDeJugadoresEn(int partida);
    void agregarJugadorAPartida(std::shared_ptr<EscuchadorCliente> cliente, int partida);
};

#endif
