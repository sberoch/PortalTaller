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
    std::cout << "Manejaondoan\n";
    unEvento.actualizar(*this);
}

void Partida::agregar(std::shared_ptr<Cliente> cliente) {
    jugadores_[cliente->uuid()] = cliente;
}

void Partida::ejecutar() {
    for (auto& kv : jugadores_) {
        std::shared_ptr<Retransmisor> retransmisor(new Retransmisor(seguirCorriendo_, kv.second->eventosEntrantes(), eventosEntrantes_));
        retransmisores_[kv.second->uuid()] = retransmisor;
        retransmisor->iniciar();
        std::shared_ptr<Evento> inicio(std::make_shared<EventoIniciarPartida>(1));
        kv.second->eventosSalientes().put(inicio);
    }
    bool obtenido;
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

void Partida::manejar(EventoJugadorDesconectado& evento) {
    int uuid = evento.atributos["uuidDelDesconectado"];
    retransmisores_[uuid]->cerrar();
    jugadores_[uuid]->cerrar();    
    jugadores_.erase(uuid);
    retransmisores_.erase(uuid);
}

void Partida::cerrar() {
    eventosEntrantes_.detener();
    for (auto& kv : retransmisores_) {
        kv.second->cerrar();
    }
    for (auto& kv : jugadores_) {
        kv.second->cerrar();
    }
    Thread::cerrar();
}