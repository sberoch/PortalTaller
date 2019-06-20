#include "cliente.h"

#include "../../Common/handler.h"
#include "../../Common/Evento.h"
#include "../../Common/Serializador.h"
#include <memory>
#include <iostream>

Cliente::Cliente(Socket&& skt) :
    sktCliente_(std::move(skt)),
    finalizado_(false),
    enviador_(eventosAEnviar_, sktCliente_),
    recibidor_(sktCliente_, eventosRecibidos_) {
}

bool Cliente::finalizado() {
    return finalizado_;
}

void Cliente::ejecutar() {
    enviador_.ejecutar();
    recibidor_.ejecutar();
}

void Cliente::detener() {
    finalizado_ = true;
    eventosAEnviar_.detener();
    eventosRecibidos_.detener();
    enviador_.detener();
    recibidor_.detener();
    sktCliente_.shutdown();
    Thread::cerrar();
}
