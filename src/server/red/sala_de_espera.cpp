#include "sala_de_espera.h"
#include "cliente.h"

#include <iostream>

SalaDeEspera::SalaDeEspera(bool& seguirCorriendo, CoordinadorPartidas& coordinadorPartidas) :
    seguirCorriendo_(seguirCorriendo),
    coordinadorPartidas_(coordinadorPartidas) {
}

void SalaDeEspera::agregar(std::shared_ptr<Cliente> unCliente) {
    // DEBERIA SER PROTEGIDO, SI INTERVIENE EL ACEPTADOR Y LA PARTIDA (UNA VEZ FINALIZADA)
    clientes_.push_back(unCliente);
    unCliente->iniciar();
    std::shared_ptr<Retransmisor> retransmisor(new Retransmisor(seguirCorriendo_, unCliente->eventosEntrantes(), eventosEntrantes_));
    retransmisores_[unCliente] = retransmisor;
    retransmisor->iniciar();
}

void SalaDeEspera::cerrar() {
    auto it = std::begin(clientes_);
    while (it != std::end(clientes_)) {
        (*it)->cerrar();
        ++it;                    
    }
    eventosEntrantes_.detener();
    for (auto& kv : retransmisores_) {
        kv.second->cerrar();
    }
    Thread::cerrar();
}

void SalaDeEspera::ejecutar() {
    bool obtenido;
    std::shared_ptr<Evento> evento;
    while(seguirCorriendo_ && (obtenido = eventosEntrantes_.get(evento))) {
        manejar(*evento);
    }
}

void SalaDeEspera::manejar(Evento& evento) {
    evento.actualizar(*this);
}

void SalaDeEspera::manejar(EventoCrearPartida& evento) {
    
}
void SalaDeEspera::manejar(EventoSeleccionarPartida& evento) {

}
void SalaDeEspera::manejar(EventoUnirseAPartida& evento) {

}
void SalaDeEspera::manejar(EventoIniciarPartida& evento) {

}

void SalaDeEspera::manejar(EventoIngresarASala& evento) {

}
