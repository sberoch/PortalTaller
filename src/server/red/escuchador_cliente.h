#ifndef __ESCUCHADOR_CLIENTE_H__
#define __ESCUCHADOR_CLIENTE_H__

#include "thread.h"
#include "protocolo.h"
#include "socket.h"

// Forward declaration
class Handler;
class Socket;

class EscuchadorCliente : public Thread {
    private:
    Socket sktCliente_;
    Handler* destinatario_;
    bool finalizado_;
    Protocolo p;

    public:
    EscuchadorCliente(Socket&& skt, Handler* unDestinatario);
    virtual void run() override;
    void stop();
    void cambiarDestinatario(Handler* nuevoDestinatario);
    bool finalizado();
};

#endif
