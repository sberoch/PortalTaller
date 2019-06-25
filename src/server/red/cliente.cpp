#include "cliente.h"

#include "../../Common/handler.h"
#include "../../Common/Evento.h"
#include "../../Common/Serializador.h"
#include <memory>
#include <iostream>

Cliente::Cliente(Socket&& skt, bool& seguirCorriendo) :
    sktCliente_(std::move(skt)),
    seguirCorriendo_(seguirCorriendo),
    enviador_(eventosAEnviar_, sktCliente_, seguirCorriendo),
    recibidor_(sktCliente_, eventosRecibidos_, seguirCorriendo, uuid()) {
}

bool Cliente::estaVivo() {
    return seguirCorriendo_;
}

void Cliente::ejecutar() {
    enviador_.iniciar();
    recibidor_.iniciar();
}

void Cliente::cerrar() {
    seguirCorriendo_ = false;
    eventosAEnviar_.detener();
    eventosRecibidos_.detener();
    sktCliente_.shutdown();
    enviador_.cerrar();
    recibidor_.cerrar();    
    Thread::cerrar();
}

void Cliente::enviar(std::shared_ptr<Evento> unEvento) {
    eventosAEnviar_.put(unEvento);
}

ColaBloqueante<std::shared_ptr<Evento>>& Cliente::eventosEntrantes() {
    return eventosRecibidos_;
}
