#include "sala_de_espera.h"
#include "cliente.h"

#include <iostream>

SalaDeEspera::SalaDeEspera(bool& seguirCorriendo) :
    seguirCorriendo_(seguirCorriendo) {
}

void SalaDeEspera::agregar(std::shared_ptr<Cliente> unCliente) {
    // DEBERIA SER PROTEGIDO
    clientes_.push_back(unCliente);
    unCliente->iniciar();
}

void SalaDeEspera::cerrar() {
    auto it = std::begin(clientes_);
    while (it != std::end(clientes_)) {
        (*it)->cerrar();
        ++it;                    
    }
    eventosEntrantes_.detener();
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
    std::cout << "RecibiCrearPartida En la sala de espera\n";
}
void SalaDeEspera::manejar(EventoSeleccionarPartida& evento) {

}
void SalaDeEspera::manejar(EventoUnirseAPartida& evento) {

}
void SalaDeEspera::manejar(EventoIniciarPartida& evento) {

}