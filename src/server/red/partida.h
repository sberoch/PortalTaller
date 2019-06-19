#ifndef __PARTIDA_H__
#define __PARTIDA_H__

#include <memory>
#include <vector>
#include "escuchador_cliente.h"
#include "../../Common/handler.h"
#include "../../Common/Evento.h"
#include "../../Common/cola_bloqueante.h"
#include "../mundo/mundo.h"

class Partida : public Handler{
    private:
    Partida(const Partida& otra) = delete;    
    Partida& operator=(const Partida& otra) = delete;
    std::vector<std::shared_ptr<EscuchadorCliente>> jugadores_;
    Mundo mundo_;
    ColaBloqueante<std::shared_ptr<Evento>> eventosEntrantes_;

    public:
    Partida();
    Partida(Partida&& otra);
    Partida& operator=(Partida&& otra);
    void agregar(std::shared_ptr<EscuchadorCliente> cliente);
    int cantidadDeJugadores();
    void iniciar();
    virtual void manejar(Evento& evento) override;
};

#endif
