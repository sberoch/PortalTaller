#include "escuchador_cliente.h"

#include "socket.h"
#include "handler.h"

EscuchadorCliente::EscuchadorCliente(Socket&& skt, Handler* unDestinatario) :
    sktCliente_(skt),
    destinatario_(unDestinatario) {
    finalizado_ = false;
}

void EscuchadorCliente::cambiarDestinatario(Handler* nuevoDestinatario) {
    destinatario_ = nuevoDestinatario;
}

bool EscuchadorCliente::finalizado() {
    return finalizado_;
}
