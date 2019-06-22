#include "aceptador.h"

#include "../server_config.h"

#include "../../Common/Socket.h"

#include "../server.h"
#include "cliente.h"
#include "sala_de_espera.h"

#include <iostream>
Aceptador::Aceptador(Socket& skt, bool& seguirCorriendo, Servidor& servidor, SalaDeEspera& salaDeEspera) :
    skt_(skt),
    seguirCorriendo_(seguirCorriendo),
    servidor_(servidor),
    salaDeEspera_(salaDeEspera) {
}

void Aceptador::ejecutar() {
    while (seguirCorriendo_) {
        try {
            Socket aceptado = skt_.aceptar();
            std::shared_ptr<Cliente> cliente(new Cliente(std::move(aceptado), seguirCorriendo_));
            salaDeEspera_.agregar(cliente);
        }
        catch(const std::exception& e) {
            std::cout << "Error en Aceptador::ejecutar() al intentar aceptar un nuevo socket\n";
        }
    }
}

void Aceptador::cerrar() {
    salaDeEspera_.cerrar();
    Thread::cerrar();
}
