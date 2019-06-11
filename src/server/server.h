#ifndef __SERVER_H__
#define __SERVER_H__

#include <string>

#include "../Common/Socket.h"
#include "../Common/handler.h"

#define HOST "localhost"
#define CONDICION_SALIR 'q'

class Servidor : public Handler {
    private:
    Socket sktAceptador_;
    
    public:
    Servidor(const std::string& unPuerto);
    void correr();
    virtual void manejar(Evento& evento) override;
};

#endif
