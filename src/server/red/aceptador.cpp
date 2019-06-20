#include "aceptador.h"

#include "../server_config.h"

#include "../../Common/Socket.h"

#include "../server.h"
#include "sala_de_espera.h"
#include "cliente.h"

Aceptador::Aceptador(Socket& skt, bool seguirCorriendo, Servidor& servidor, SalaDeEspera& salaDeEspera) :
    skt_(skt),
    seguirCorriendo_(seguirCorriendo),
    servidor_(servidor),
    salaDeEspera_(salaDeEspera) {
}

#include <iostream>
void Aceptador::ejecutar() {

    while (seguirCorriendo_) {
        try {
            Socket aceptado = skt_.aceptar();
            std::shared_ptr<Cliente> cliente(new Cliente(std::move(aceptado)));
            salaDeEspera_.agregar(cliente);
        }
        catch(const std::exception& e) {
            std::cout << "Error en aceptar\n";
        }
    }
}

void Aceptador::detener() {
    salaDeEspera_.cerrar();
    Thread::cerrar();
}
