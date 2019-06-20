#include "enviador_eventos.h"

#include "../../Common/Evento.h"

EnviadorEventos::EnviadorEventos(ColaBloqueante<std::shared_ptr<Evento>>& origen, Socket& destino) :
    origen_(origen),
    destino_(destino),
    finalizado_(false) {
}

void EnviadorEventos::ejecutar() {
    bool obtenido;
    std::shared_ptr<Evento> eventoAEnviar;
    while(!finalizado_ && (obtenido = origen_.get(eventoAEnviar))) {
        eventoAEnviar->enviarPorSocket(destino_);
    }
}

void EnviadorEventos::detener() {
    finalizado_ = true;
    Thread::cerrar();
}
