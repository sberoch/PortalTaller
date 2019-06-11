#include "aceptador.h"

#include "../server_config.h"

#include "../../Common/Socket.h"
#include "escuchador_cliente.h"
#include "../server.h"


Aceptador::Aceptador(Socket& skt, ValueProtected<bool>& seguirCorriendo, Servidor& servidor) :
    skt_(skt),
    seguirCorriendo_(seguirCorriendo),
    servidor_(servidor) {
}

void Aceptador::ejecutar() {

    while (seguirCorriendo_()) {
        try {
            Socket aceptado = skt_.aceptar();
            clientes_.push_back(new EscuchadorCliente(std::move(aceptado), &servidor_));
            clientes_.back()->iniciar();
            auto it = std::begin(clientes_);
            while (it != std::end(clientes_)) {
                if ((*it)->finalizado()) {
                    (*it)->cerrar();
                    delete (*it);
                    it = clientes_.erase(it);
                } else {
                    ++it;
                }                    
            }
        }
        catch(const std::exception& e) {
            continue;
        }
    }
}

void Aceptador::cerrar() {
    auto it = std::begin(clientes_);
    while (it != std::end(clientes_)) {
        (*it)->stop();
        (*it)->cerrar();
        delete (*it);
        ++it;                    
    }
    Thread::cerrar();
}
