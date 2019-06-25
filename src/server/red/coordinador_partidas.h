#ifndef __COORDINADOR_PARTIDAS_H__
#define __COORDINADOR_PARTIDAS_H__

#include "../../Common/Thread.h"
#include "../../Common/cola_bloqueante.h"
#include "../../Common/Evento.h"
#include "../../Common/handler.h"

#include "partida.h"

//Forward declaration
class Evento;

class CoordinadorPartidas : public Thread, public Handler {
    private:
    bool& seguirCorriendo_;
    ColaBloqueante<std::shared_ptr<Evento>> eventosEntrantes_;
    std::vector<Partida> partidas_;

    public:
    CoordinadorPartidas(bool& seguirCorriendo);
    virtual void ejecutar() override;
    virtual void cerrar() override;

    virtual void manejar(Evento& evento) override;
    
    int cantidadPartidas();
    void agregarPartida();
};

#endif
