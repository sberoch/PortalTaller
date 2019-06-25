#include "sala_de_espera.h"
#include "cliente.h"

#include <iostream>

SalaDeEspera::SalaDeEspera(bool& seguirCorriendo) :
    seguirCorriendo_(seguirCorriendo) {
}

void SalaDeEspera::agregar(std::shared_ptr<Cliente> unCliente) {
    std::lock_guard<std::mutex> lck(mtx_);
    clientes_[unCliente->uuid()] = unCliente;
    unCliente->iniciar();
    std::shared_ptr<Retransmisor> retransmisor(new Retransmisor(seguirCorriendo_, unCliente->eventosEntrantes(), eventosEntrantes_));
    retransmisores_[unCliente->uuid()] = retransmisor;
    retransmisor->iniciar();
}

void SalaDeEspera::cerrar() {
    for (auto& kv : clientes_) {
        kv.second->cerrar();
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
    coordinadorPartidas_.agregarPartida();
    int cantidadDePartidas = coordinadorPartidas_.cantidadPartidas();
    for (auto& kv : clientes_) {
        std::shared_ptr<Evento> e(std::make_shared<EventoActualizacionSala>(cantidadDePartidas,0,0));
        kv.second->eventosSalientes().put(e);
    }

}

void SalaDeEspera::manejar(EventoSeleccionarPartida& evento) {
    int partidaSeleccionada = evento.atributos["partidaSeleccionada"] -1;
    int cantidadPartidas = coordinadorPartidas_.cantidadPartidas();
    int cantidadJugadores = coordinadorPartidas_.cantidadDeJugadoresEnPartida(partidaSeleccionada);
    for (auto& kv : clientes_) {
        std::shared_ptr<Evento> e(std::make_shared<EventoActualizacionSala>(cantidadPartidas,partidaSeleccionada,cantidadJugadores));
        kv.second->eventosSalientes().put(e);
    }
    
}
void SalaDeEspera::manejar(EventoUnirseAPartida& evento) {
    int partidaSeleccionada = evento.atributos["partidaSeleccionada"] -1;
    int uuid = evento.atributos["uuid"];
    std::shared_ptr<Cliente> cliente = clientes_[uuid];
    coordinadorPartidas_.moverClienteAPartida(cliente, partidaSeleccionada);
    int cantidadJugadores = coordinadorPartidas_.cantidadDeJugadoresEnPartida(partidaSeleccionada);
        
    int cantidadDePartidas = coordinadorPartidas_.cantidadPartidas();
    for (auto& kv : clientes_) {
        std::shared_ptr<Evento> e(std::make_shared<EventoActualizacionSala>(cantidadDePartidas,partidaSeleccionada,cantidadJugadores));
        kv.second->eventosSalientes().put(e);
    }
}

void SalaDeEspera::manejar(EventoIniciarPartida& evento) {
    
}

void SalaDeEspera::manejar(EventoIngresarASala& evento) {
    std::shared_ptr<Cliente> solicitante = clientes_[evento.atributos["uuid"]];
    int cantidadDePartidas = coordinadorPartidas_.cantidadPartidas();

    std::shared_ptr<Evento> e(new EventoActualizacionSala(cantidadDePartidas,cantidadDePartidas,0));
    solicitante->eventosSalientes().put(e);
}

void SalaDeEspera::manejar(EventoJugadorDesconectado& evento) {
    
    int uuid = evento.atributos["uuidDelDesconectado"];
    clientes_[uuid]->cerrar();
    retransmisores_[uuid]->cerrar();
    clientes_.erase(uuid);
    retransmisores_.erase(uuid);
}