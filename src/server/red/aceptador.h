#ifndef __ACEPTADOR_H__
#define __ACEPTADOR_H__

#include "../../Common/Thread.h"

// Forward declaration
class Socket;
class Servidor;
class Cliente;
class SalaDeEspera;

class Aceptador : public Thread {
    private:
    Socket& skt_;
    bool& seguirCorriendo_;
    Servidor& servidor_;
    SalaDeEspera& salaDeEspera_;

    public:
    Aceptador(Socket& skt, bool& seguirCorriendo, Servidor& servidor, SalaDeEspera& salaDeEspera);
    virtual void ejecutar() override;
    virtual void cerrar() override;
};

#endif
