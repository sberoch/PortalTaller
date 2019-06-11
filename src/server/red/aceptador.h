#ifndef __ACEPTADOR_H__
#define __ACEPTADOR_H__

#include <vector>

#include "../../Common/Thread.h"
#include "../../Common/value_protected.h"

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
    virtual void ejecutar() override;
    virtual void cerrar() override;
};

#endif
