#include "server.h"

#include <iostream>

#include "red/aceptador.h"

#include "../Common/value_protected.h"

#include "server_config.h"


Servidor::Servidor(const std::string& unPuerto) {
    sktAceptador_.vincularYEscuchar(unPuerto.c_str(), CONFIG.MAX_EN_ESPERA);
}

void Servidor::correr() {
    ValueProtected<bool> seguirCorriendo(true);
    Aceptador aceptador(sktAceptador_, seguirCorriendo, salaDeEspera_, *this);
    aceptador.iniciar();
    char c;
    while ((c = std::cin.get()) != CONDICION_SALIR) {
        // pass
    }
    seguirCorriendo.set(false);
    sktAceptador_.shutdown();
    aceptador.cerrar();
}

void Servidor::manejar(Evento& unEvento) {
    unEvento.actualizar(*this);
}

void Servidor::manejar(EventoCrearPartida& evento) {
    Partida nuevaPartida;
    coordinador_.agregarPartida(std::move(nuevaPartida));
    EventoActualizacionSala e(coordinador_.cantidadPartidas(), 1, 0);
    salaDeEspera_.transmitir(e);
}

void Servidor::manejar(EventoSeleccionarPartida& evento) {
    int partidaSeleccionada = evento.atributos["partidaSeleccionada"] -1;
    EventoActualizacionSala e(coordinador_.cantidadPartidas(), partidaSeleccionada, coordinador_.cantidadDeJugadoresEn(partidaSeleccionada));
    salaDeEspera_.transmitir(e, evento.atributos["uuid"]);
}

void Servidor::manejar(EventoUnirseAPartida& evento) {
    int partidaSeleccionada = evento.atributos["partidaSeleccionada"] -1;
    salaDeEspera_.moverClienteAPartida(evento.atributos["uuid"], partidaSeleccionada, coordinador_);
}

void Servidor::manejar(EventoIniciarPartida& evento) {
    int partidaSeleccionada = evento.atributos["partidaSeleccionada"] -1;
    coordinador_.iniciar(partidaSeleccionada);
}
