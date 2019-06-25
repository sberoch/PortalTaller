#ifndef __CLIENTE_H__
#define __CLIENTE_H__

#include "../../Common/Thread.h"
#include "../../Common/Socket.h"
#include "../../Common/cola_bloqueante.h"

#include "../mundo/identificable.h"

#include "enviador_eventos.h"
#include "recibidor_eventos.h"
// Forward declaration
class Evento;

class Cliente : public Thread, public Identificable {
    private:
    Socket sktCliente_;
    bool& seguirCorriendo_;
    ColaBloqueante<std::shared_ptr<Evento>> eventosRecibidos_;
    ColaBloqueante<std::shared_ptr<Evento>> eventosAEnviar_;
    EnviadorEventos enviador_;
    RecibidorEventos recibidor_;

    public:
    Cliente(Socket&& skt, bool& seguirCorriendo);
    virtual void ejecutar() override;
    virtual void cerrar() override;
    bool estaVivo();
    void enviar(std::shared_ptr<Evento> unEvento);
    ColaBloqueante<std::shared_ptr<Evento>>& eventosEntrantes();
};

#endif
