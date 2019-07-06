#include "partida.h"
#include <iostream>

Partida::Partida(bool& seguirCorriendo) :
    seguirCorriendo_(seguirCorriendo) {
    jugando_ = false;
}

int Partida::cantidadDeJugadores() {
    return jugadores_.size();
}

void Partida::manejar(Evento& unEvento) {
  
    unEvento.actualizar(*this);
}

void Partida::agregar(std::shared_ptr<Cliente> cliente) {
    jugadores_[cliente->uuid()] = cliente;
}

void Partida::ejecutar() {
    jugando_ = true;
    for (auto& kv : jugadores_) {
        kv.second->eventosEntrantes().reiniciar();
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
    if (!seguirCorriendo_) {
        return;
    }
    std::cout << "El cliente abandono la parida\n";
    int uuid = evento.atributos["uuidDelDesconectado"];
    jugadores_[uuid]->cerrar();    
    jugadores_.erase(uuid);
    retransmisores_[uuid]->cerrar();
    retransmisores_.erase(uuid);
}

void Partida::cerrar() {
    if (!jugando_) {
        return;
    }
    eventosEntrantes_.detener();
    for (auto& kv : jugadores_) {
        kv.second->cerrar();
        std::cout << "closing\n";
    }    
    for (auto& kv : retransmisores_) {
        kv.second->cerrar();
        std::cout << "closing\n";
    }    
    Thread::cerrar();
}

void Partida::manejar(EventoCreacionPersonaje& evento) {
    std::cout << "pidio\n";
}