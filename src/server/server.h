#ifndef __SERVER_H__
#define __SERVER_H__

#include <string>
#include <vector>

#include "../Common/Socket.h"
#include "../Common/Evento.h"

#include "red/sala_de_espera.h"

#define HOST "localhost"
#define CONDICION_SALIR 'q'

class Servidor {
    private:
    Socket sktAceptador_;
    SalaDeEspera salaDeEspera_;
    
    public:
    Servidor(const std::string& unPuerto);
    void correr();
};

#endif
