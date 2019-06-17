#ifndef __SERVER_H__
#define __SERVER_H__

#include <string>
#include <vector>

#include "../Common/Socket.h"
#include "../Common/handler.h"
#include "../Common/Evento.h"

#include "red/sala.h"
#include "red/sala_de_espera.h"

#define HOST "localhost"
#define CONDICION_SALIR 'q'

class Servidor : public Handler {
    private:
    Socket sktAceptador_;
    SalaDeEspera salaDeEspera_;
    std::vector<Sala> salas_;
    
    public:
    Servidor(const std::string& unPuerto);
    void correr();
    virtual void manejar(Evento& evento) override;
    virtual void manejar(EventoCrearPartida& evento) override;
    virtual void manejar(EventoActualizacionSala& evento) override;
};

#endif

