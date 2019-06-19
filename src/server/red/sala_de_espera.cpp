#include "sala_de_espera.h"
#include "escuchador_cliente.h"
#include "coordinador_partidas.h"

void SalaDeEspera::agregar(std::shared_ptr<EscuchadorCliente> unCliente) {
    std::lock_guard<std::mutex> lck(mtx_);
    clientes_.push_back(unCliente);
}

void SalaDeEspera::moverClienteAPartida(int uuidCliente, int partidaSeleccionada, CoordinadorPartidas& coordinador) {
    std::lock_guard<std::mutex> lck(mtx_);
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
    std::lock_guard<std::mutex> lck(mtx_);
    auto it = std::begin(clientes_);
    while (it != std::end(clientes_)) {
        (*it)->manejar(unEvento);
        ++it;                    
    }
}

void SalaDeEspera::transmitir(Evento& unEvento, int destinatario) {
    std::lock_guard<std::mutex> lck(mtx_);
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
    std::lock_guard<std::mutex> lck(mtx_);
    auto it = std::begin(clientes_);
    while (it != std::end(clientes_)) {
        (*it)->stop();
        (*it)->cerrar();
        ++it;                    
    }
}