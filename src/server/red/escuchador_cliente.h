#ifndef __ESCUCHADOR_CLIENTE_H__
#define __ESCUCHADOR_CLIENTE_H__

#include "../../Common/Thread.h"
#include "../../Common/handler.h"
#include "../../Common/Socket.h"
#include "../mundo/identificable.h"

// Forward declaration
class Evento;

class EscuchadorCliente : public Thread, public Handler, public Identificable {
    private:
    Socket sktCliente_;
    Handler* destinatario_;
    bool finalizado_;

    public:
    EscuchadorCliente(Socket&& skt, Handler* unDestinatario);
    virtual void ejecutar() override;
    virtual void manejar(Evento& unEvento) override;
    void stop();
    void cambiarDestinatario(Handler* nuevoDestinatario);
    bool finalizado();
};

#endif
