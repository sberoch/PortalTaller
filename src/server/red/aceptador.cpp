#include "aceptador.h"

#include "../server_config.h"

#include "../../Common/Socket.h"
#include "escuchador_cliente.h"
#include "../server.h"
#include "sala_de_espera.h"

Aceptador::Aceptador(Socket& skt, ValueProtected<bool>& seguirCorriendo, SalaDeEspera& salaDeEspera, Servidor& servidor) :
    skt_(skt),
    seguirCorriendo_(seguirCorriendo),
    salaDeEspera_(salaDeEspera),
    servidor_(servidor) {
}

void Aceptador::ejecutar() {

    while (seguirCorriendo_()) {
        try {
            Socket aceptado = skt_.aceptar();
            std::shared_ptr<EscuchadorCliente> cliente(new EscuchadorCliente(std::move(aceptado), &servidor_));
            salaDeEspera_.agregar(cliente);
            cliente->iniciar();
            
            //Limpiar clientes desconectados, acá o en la sala.
            
            /*auto it = std::begin(clientes_);
            while (it != std::end(clientes_)) {
                if ((*it)->finalizado()) {
                    (*it)->cerrar();
                    delete (*it);
                    it = clientes_.erase(it);
                } else {
                    ++it;
                }                    
            }*/
        }
        catch(const std::exception& e) {
            continue;
        }
    }
}

void Aceptador::cerrar() {
    salaDeEspera_.cerrar();
    Thread::cerrar();
}
