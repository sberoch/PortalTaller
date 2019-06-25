#include "partida.h"
#include <iostream>

Partida::Partida(bool& seguirCorriendo) :
    seguirCorriendo_(seguirCorriendo) {

}

Partida::Partida(Partida&& otra) : 
    seguirCorriendo_(otra.seguirCorriendo_) {
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

void Partida::ejecutar() {
    for (auto& kv : jugadores_) {
        std::shared_ptr<Retransmisor> retransmisor(new Retransmisor(seguirCorriendo_, kv.second->eventosEntrantes(), eventosEntrantes_));
        retransmisores_[kv.second->uuid()] = retransmisor;
        retransmisor->iniciar();
    }
    bool obtenido;
    std::cout << "a la escucha\n";
    std::shared_ptr<Evento> evento;    
    while(seguirCorriendo_ && (obtenido = eventosEntrantes_.get(evento))) {
        manejar(*evento);
    }
}

std::vector<int> Partida::jugadores() {
    std::vector<int> presentes;
    for (auto& kv : jugadores_) {
        presentes.push_back(kv.first);
    }
    return presentes;
}

void Partida::cerrar() {
    for (auto& kv : jugadores_) {
        kv.second->cerrar();
    }
    eventosEntrantes_.detener();
    for (auto& kv : retransmisores_) {
        kv.second->cerrar();
    }
    Thread::cerrar();
}
