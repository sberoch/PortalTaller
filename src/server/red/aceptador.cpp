#include "aceptador.h"

#include "../server_config.h"

#include "socket.h"
#include "escuchador_cliente.h"
#include "../server.h"


Aceptador::Aceptador(Socket& skt, ValueProtected<bool>& seguirCorriendo, Servidor& servidor) :
    skt_(skt),
    seguirCorriendo_(seguirCorriendo),
    servidor_(servidor) {
}

void Aceptador::run() {
    skt_.enlazar();
    skt_.escuchar(CONFIG.MAX_EN_ESPERA);

    while (seguirCorriendo_()) {
        try {
            Socket aceptado = skt_.aceptar();
            clientes_.push_back(new EscuchadorCliente(std::move(aceptado), &servidor_));
            auto it = std::begin(clientes_);
            while (it != std::end(clientes_)) {
                if ((*it)->finalizado()) {
                    (*it)->join();
                    delete (*it);
                    it = clientes_.erase(it);
                } else {
                    ++it;
                }                    
            }
        }
        catch(const std::exception& e) {
            break;
        }
    }
}

void Aceptador::join() {
    // Join de todos los threads que están en ejecución.
}
