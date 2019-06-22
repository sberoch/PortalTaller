#ifndef __SALA_ESPERA_H__
#define __SALA_ESPERA_H__

#include <vector>
#include <memory>

// Forward declaration
class Cliente;
class Evento;
class CoordinadorPartidas;

class SalaDeEspera {
    private:
    std::vector<std::shared_ptr<Cliente>> clientes_;

    public:
    void agregar(std::shared_ptr<Cliente> unCliente);

    void moverClienteAPartida(int uuidCliente, int partidaSeleccionada, CoordinadorPartidas& coordinador);

    void transmitir(Evento& unEvento);

    void transmitir(Evento& unEvento, int destinatario);

    void cerrar();
};

#endif


#ifndef __SERVER_H__
#define __SERVER_H__

#include <string>
#include <vector>

#include "../Common/Socket.h"
#include "../Common/handler.h"
#include "../Common/Evento.h"

#include "red/partida.h"
#include "red/coordinador_partidas.h"
#include "red/sala_de_espera.h"

#define HOST "localhost"
#define CONDICION_SALIR 'q'

class Servidor : public Handler {
    private:
    Socket sktAceptador_;
    SalaDeEspera salaDeEspera_;
    CoordinadorPartidas coordinador_;
    
    public:
    Servidor(const std::string& unPuerto);
    void correr();
    virtual void manejar(Evento& evento) override;
    virtual void manejar(EventoCrearPartida& evento) override;
    virtual void manejar(EventoSeleccionarPartida& evento) override;
    virtual void manejar(EventoUnirseAPartida& evento) override;
    virtual void manejar(EventoIniciarPartida& evento) override;
};

#endif

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