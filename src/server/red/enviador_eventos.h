#ifndef __ENVIADOR_EVENTOS_H__
#define __ENVIADOR_EVENTOS_H__

#include <memory>

#include "../../Common/cola_bloqueante.h"
#include "../../Common/Thread.h"

//Forward declaration
class Socket;
class Evento;

class EnviadorEventos : public Thread {
    private:
    ColaBloqueante<std::shared_ptr<Evento>>& origen_;
    Socket& destino_;
    bool finalizado_;

    public:
    EnviadorEventos(ColaBloqueante<std::shared_ptr<Evento>>& origen, Socket& destino);
    virtual void ejecutar() override;
    void detener();
};

#endif
