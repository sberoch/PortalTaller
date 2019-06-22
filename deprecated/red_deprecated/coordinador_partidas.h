#ifndef __COORDINADOR_PARTIDAS_H__
#define __COORDINADOR_PARTIDAS_H__

#include <vector>
#include <memory>
#include "cliente.h"

#include "partida.h"

class CoordinadorPartidas {
    private:
    std::vector<Partida> partidas_;

    public:
    void agregarPartida(Partida&& unaPartida);
    int cantidadPartidas();
    int cantidadDeJugadoresEn(int partida);
    void agregarJugadorAPartida(std::shared_ptr<Cliente> cliente, int partida);
    void iniciar(int partidaSeleccionada);
};

#endif
