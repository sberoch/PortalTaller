#include "escuchador_cliente.h"

#include "../../Common/handler.h"
#include "../../Common/Evento.h"

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

void EscuchadorCliente::ejecutar() {
    int idCrearJugador = 214;
    int idJugador = 29;
    sktCliente_.enviarInt(idCrearJugador);
    sktCliente_.enviarInt(idJugador);
}

void EscuchadorCliente::stop() {
    sktCliente_.shutdown();
}
