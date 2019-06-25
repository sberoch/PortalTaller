#include "retransmisor.h"
#include <iostream>

Retransmisor::Retransmisor(bool& seguirCorriendo,
    ColaBloqueante<std::shared_ptr<Evento>>& origen,
    ColaBloqueante<std::shared_ptr<Evento>>& destino) :
    seguirCorriendo_(seguirCorriendo),
    origen_(origen),
    destino_(destino) {
}

void Retransmisor::ejecutar() {
    bool obtenido;
    std::shared_ptr<Evento> evento;
    while(seguirCorriendo_ && (obtenido = origen_.get(evento))) {
        destino_.put(evento);
    }
}

void Retransmisor::cerrar() {
    Thread::cerrar();
}
