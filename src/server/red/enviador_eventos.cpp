#include "enviador_eventos.h"

#include "../../Common/Evento.h"

EnviadorEventos::EnviadorEventos(ColaBloqueante<std::shared_ptr<Evento>>& origen, Socket& destino, bool& seguirCorriendo) :
    origen_(origen),
    destino_(destino),
    seguirCorriendo_(seguirCorriendo) {
}

void EnviadorEventos::ejecutar() {
    bool obtenido;
    std::shared_ptr<Evento> eventoAEnviar;
    while(seguirCorriendo_ && (obtenido = origen_.get(eventoAEnviar))) {
        eventoAEnviar->enviarPorSocket(destino_);
    }
}

void EnviadorEventos::cerrar() {
    Thread::cerrar();
}
