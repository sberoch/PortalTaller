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
    std::cout << "Agregado\n";
}
