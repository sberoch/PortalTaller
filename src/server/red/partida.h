#ifndef __PARTIDA_H__
#define __PARTIDA_H__

#include <memory>
#include <vector>
#include "cliente.h"
#include "../../Common/handler.h"
#include "../../Common/Thread.h"
#include "../../Common/Evento.h"
#include "../../Common/cola_bloqueante.h"
#include "../mundo/mundo.h"
#include "retransmisor.h"

class Partida : public Handler, public Thread {
    private:
    bool& seguirCorriendo_;
    Partida(const Partida& otra) = delete;    
    Partida& operator=(const Partida& otra) = delete;
    std::map<int, std::shared_ptr<Cliente>> jugadores_;
    Mundo mundo_;
    ColaBloqueante<std::shared_ptr<Evento>> eventosEntrantes_;
    std::map<int, std::shared_ptr<Retransmisor>> retransmisores_;

    public:
    Partida(bool& seguirCorriendo);
    Partida(Partida&& otra);
    Partida& operator=(Partida&& otra);
    void agregar(std::shared_ptr<Cliente> cliente);
    int cantidadDeJugadores();
    virtual void manejar(Evento& evento) override;
    std::vector<int> jugadores();

    virtual void ejecutar() override;
    virtual void cerrar() override;
};

#endif
