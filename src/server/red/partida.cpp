#include "partida.h"
#include <iostream>
Partida::Partida() {
    
}

Partida::Partida(Partida&& otra) {

}

Partida& Partida::operator=(Partida&& otra) {
    if (this == &otra) {
        return *this;
    }
    return *this; 
}

int Partida::cantidadDeJugadores() {
    return jugadores_.size();
}

void Partida::manejar(Evento& unEvento) {
    unEvento.actualizar(*this);
}

void Partida::agregar(std::shared_ptr<EscuchadorCliente> cliente) {
    jugadores_.push_back(cliente);
}

void Partida::iniciar() {
    auto it = std::begin(jugadores_);
    while (it != std::end(jugadores_)) {
        EventoIniciarPartida e(0);
        (*it)->manejar(e);
        (*it)->cambiarDestinatario(this);
        ++it;                    
    }
}

void Partida::manejar(EventoMover& evento) {
    std::cout << "Estoy recibiendo mover del jugador: " << evento.atributos["uuid"] << "\n";
}