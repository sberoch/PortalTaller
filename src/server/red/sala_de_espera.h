#ifndef __SALA_DE_ESPERA_H__
#define __SALA_DE_ESPERA_H__

#include <vector>
#include <memory>
#include <map>

#include "../../Common/cola_bloqueante.h"
#include "../../Common/Evento.h"
#include "../../Common/handler.h"
#include "../../Common/Thread.h"

#include "retransmisor.h"
#include "coordinador_partidas.h"

#include <mutex>

// Forward declaration
class Cliente;

class SalaDeEspera : public Thread, public Handler {
    private:
    bool& seguirCorriendo_;
    CoordinadorPartidas& coordinadorPartidas_;
    std::map<int, std::shared_ptr<Cliente>> clientes_;
    ColaBloqueante<std::shared_ptr<Evento>> eventosEntrantes_;
    std::map<int, std::shared_ptr<Retransmisor>> retransmisores_;
    std::mutex mtx_;

    public:
    SalaDeEspera(bool& seguirCorriendo, CoordinadorPartidas& coordinadorPartidas);
    void agregar(std::shared_ptr<Cliente> unCliente);
    virtual void ejecutar() override;
    virtual void cerrar() override;
    
    virtual void manejar(Evento& evento) override;
    virtual void manejar(EventoCrearPartida& evento) override;
    virtual void manejar(EventoSeleccionarPartida& evento) override;
    virtual void manejar(EventoUnirseAPartida& evento) override;
    virtual void manejar(EventoIniciarPartida& evento) override;
    virtual void manejar(EventoIngresarASala& evento) override;
    virtual void manejar(EventoJugadorDesconectado& evento) override;
};

#endif
