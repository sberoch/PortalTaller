#include "escuchador_cliente.h"
#include "handler.h"

#include "../Common/Evento.h"

EscuchadorCliente::EscuchadorCliente(Socket&& skt, Handler* unDestinatario) :
    destinatario_(unDestinatario) {
    sktCliente_ = std::move(skt);
    finalizado_ = false;
}

void EscuchadorCliente::cambiarDestinatario(Handler* nuevoDestinatario) {
    destinatario_ = nuevoDestinatario;
}

bool EscuchadorCliente::finalizado() {
    return finalizado_;
}

void EscuchadorCliente::run() {
    int idCrearJugador = 214;
    int idJugador = 29;
    p.enviar(idCrearJugador, sktCliente_);
    p.enviar(idCrearJugador, sktCliente_);
}

void EscuchadorCliente::stop() {
    sktCliente_.cerrar();
}
