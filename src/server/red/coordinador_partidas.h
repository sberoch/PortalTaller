#ifndef __COORDINADOR_PARTIDAS_H__
#define __COORDINADOR_PARTIDAS_H__

#include "../../Common/Thread.h"
#include "../../Common/cola_bloqueante.h"

#include "partida.h"

//Forward declaration
class Evento;

class CoordinadorPartidas : public Thread {
    private:
    bool& seguirCorriendo_;
    ColaBloqueante<std::shared_ptr<Evento>> eventosEntrantes_;
    std::vector<Partida> partidas_;

    public:
    CoordinadorPartidas(bool& seguirCorriendo);
    virtual void ejecutar() override;
    virtual void cerrar() override;

    int cantidadPartidas();
    void agregarPartida();
};

#endif
