#ifndef __ACEPTADOR_H__
#define __ACEPTADOR_H__

#include <vector>

#include "thread.h"
#include "value_protected.h"

// Forward declaration
class Socket;
class Servidor;
class EscuchadorCliente;

class Aceptador : public Thread {
    private:
    Socket& skt_;
    ValueProtected<bool>& seguirCorriendo_;
    Servidor& servidor_;
    std::vector<EscuchadorCliente*> clientes_;

    public:
    Aceptador(Socket& skt, ValueProtected<bool>& seguirCorriendo, Servidor& servidor);
    virtual void run() override;
    virtual void join() override;
};

#endif
