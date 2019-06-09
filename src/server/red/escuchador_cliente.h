#ifndef __ESCUCHADOR_CLIENTE_H__
#define __ESCUCHADOR_CLIENTE_H__

#include "thread.h"

// Forward declaration
class Handler;
class Socket;

class EscuchadorCliente : public Thread {
    private:
    Socket& sktCliente_;
    Handler* destinatario_;
    bool finalizado_;

    public:
    EscuchadorCliente(Socket&& skt, Handler* unDestinatario);
    virtual void run() override;
    void cambiarDestinatario(Handler* nuevoDestinatario);
    bool finalizado();
};

#endif
