#include "escuchador_cliente.h"

#include "../../Common/handler.h"
#include "../../Common/Evento.h"
#include "../../Common/Serializador.h"

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
    Serializador serializador;
    uuid_ = uuid();
    Evento* evento = new EventoCreacionPersonaje(uuid_);
	evento->enviarPorSocket(sktCliente_);
    while (true) {
		Evento* evento = serializador.recibirEvento(sktCliente_);
        evento->atributos["uuid"] = uuid_;
		destinatario_->manejar(*evento);
	}    
}

void EscuchadorCliente::stop() {
    sktCliente_.shutdown();
}

void EscuchadorCliente::manejar(Evento& unEvento) {
    unEvento.enviarPorSocket(sktCliente_);
}
