#ifndef __SERVER_H__
#define __SERVER_H__

#include <string>

#include "red/socket.h"

#define HOST "localhost"
#define CONDICION_SALIR 'q'

class Servidor {
    private:
    Socket sktAceptador_;
    public:
    Servidor(const std::string& unPuerto);
    void correr();
};

#endif
