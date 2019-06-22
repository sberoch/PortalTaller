#ifndef __RECIBIDOR_EVENTOS_H__
#define __RECIBIDOR_EVENTOS_H__

#include <memory>

#include "../../Common/cola_bloqueante.h"
#include "../../Common/Thread.h"
#include "../../Common/Serializador.h"

//Forward declaration
class Socket;
class Evento;

class RecibidorEventos : public Thread {
    private:
    Socket& origen_;
    ColaBloqueante<std::shared_ptr<Evento>>& destino_;    
    bool& seguirCorriendo_;
    Serializador serializador_;

    public:
    RecibidorEventos(Socket& origen, ColaBloqueante<std::shared_ptr<Evento>>& destino, bool& seguirCorriendo);
    virtual void ejecutar() override;
    void cerrar() override;
};

#endif
