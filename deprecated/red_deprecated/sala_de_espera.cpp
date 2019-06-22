#include "sala_de_espera.h"
#include "cliente.h"
#include "coordinador_partidas.h"

void SalaDeEspera::agregar(std::shared_ptr<Cliente> unCliente) {
    clientes_.push_back(unCliente);
}

void SalaDeEspera::moverClienteAPartida(int uuidCliente, int partidaSeleccionada, CoordinadorPartidas& coordinador) {
    auto it = std::begin(clientes_);
    while (it != std::end(clientes_)) {
        if ((*it)->uuid() == uuidCliente) {
            coordinador.agregarJugadorAPartida((*it), partidaSeleccionada);
            break;
        }        
        ++it;                    
    }
}


void SalaDeEspera::transmitir(Evento& unEvento) {
    auto it = std::begin(clientes_);
    while (it != std::end(clientes_)) {
        (*it)->manejar(unEvento);
        ++it;                    
    }
}

void SalaDeEspera::transmitir(Evento& unEvento, int destinatario) {
    auto it = std::begin(clientes_);
    while (it != std::end(clientes_)) {
        if ((*it)->uuid() == destinatario) {
            (*it)->manejar(unEvento);
            break;
        }        
        ++it;                    
    }
}

void SalaDeEspera::cerrar() {
    auto it = std::begin(clientes_);
    while (it != std::end(clientes_)) {
        (*it)->stop();
        (*it)->cerrar();
        ++it;                    
    }
}