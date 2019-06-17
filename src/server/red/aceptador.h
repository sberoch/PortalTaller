#ifndef __ACEPTADOR_H__
#define __ACEPTADOR_H__

#include <vector>

#include "../../Common/Thread.h"
#include "../../Common/value_protected.h"

// Forward declaration
class Socket;
class Servidor;
class EscuchadorCliente;
class SalaDeEspera;

class Aceptador : public Thread {
    private:
    Socket& skt_;
    ValueProtected<bool>& seguirCorriendo_;
    Servidor& servidor_;
    SalaDeEspera& salaDeEspera_;

    public:
    Aceptador(Socket& skt, ValueProtected<bool>& seguirCorriendo, SalaDeEspera& salaDeEspera, Servidor& servidor);
    virtual void ejecutar() override;
    virtual void cerrar() override;
};

#endif
