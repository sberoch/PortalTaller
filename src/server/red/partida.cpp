#include "partida.h"
#include <iostream>
Partida::Partida() {

}

Partida::Partida(Partida&& otra) {
    // Falta implementar
}

Partida& Partida::operator=(Partida&& otra) {
    // Falta implementar    
    if (this == &otra) {
        return *this;
    }
    return *this; 
}

int Partida::cantidadDeJugadores() {
    return jugadores_.size();
}

void Partida::manejar(Evento& unEvento) {

}

void Partida::agregar(std::shared_ptr<Cliente> cliente) {
    jugadores_[cliente->uuid()] = cliente;
}

void Partida::iniciar() {
 
}
