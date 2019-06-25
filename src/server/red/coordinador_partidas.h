#ifndef __COORDINADOR_PARTIDAS_H__
#define __COORDINADOR_PARTIDAS_H__

#include "partida.h"
#include <vector>

class CoordinadorPartidas {
    private:
    std::vector<std::shared_ptr<Partida>> partidas_;
    bool& seguirCorriendo_;

    public:
    CoordinadorPartidas(bool& seguirCorriendo);
    int cantidadPartidas();
    int cantidadDeJugadoresEnPartida(int partida);
    void agregarPartida();
    void moverClienteAPartida(std::shared_ptr<Cliente> cliente, int partida);
    std::vector<int> jugadoresEnLaPartida(int partida);
    void iniciarPartida(int partida);
    ~CoordinadorPartidas();
};

#endif
