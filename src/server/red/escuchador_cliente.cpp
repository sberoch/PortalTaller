#include "escuchador_cliente.h"

#include "../../Common/handler.h"
#include "../../Common/Evento.h"
#include "../../Common/Serializador.h"
#include <memory>
#include <iostream>

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
    std::shared_ptr<Evento> evento(new EventoCreacionPersonaje(uuid_));
	evento->enviarPorSocket(sktCliente_);
    while (true) {
		try {            
            std::shared_ptr<Evento> evento(serializador.recibirEvento(sktCliente_));
            evento->atributos["uuid"] = uuid_;
		    destinatario_->manejar(*evento);
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
            break;
        }       
	}
}

void EscuchadorCliente::stop() {
    sktCliente_.shutdown();
}

void EscuchadorCliente::manejar(Evento& unEvento) {
    unEvento.enviarPorSocket(sktCliente_);
}
