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
    Sala nuevaSala;
    salas_.push_back(std::move(nuevaSala));
    auto it = std::begin(salas_);
    int n_partidas = 0;
    while (it != std::end(salas_)) {
        n_partidas++;
        ++it;                    
    }
    std::cout << "Sala creada y guardada" << "\n";
    EventoActualizacionSala e(n_partidas, 1, 0);
    salaDeEspera_.transmitir(e);
}

void Servidor::manejar(EventoSeleccionarPartida& evento) {
    std::cout << "RecibiSelecionar partida\n";
    EventoActualizacionSala e(salas_.size(), evento.atributos["partidaSeleccionada"] -1, 2);
    salaDeEspera_.transmitir(e);
}
