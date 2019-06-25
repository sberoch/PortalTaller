#include "recibidor_eventos.h"

#include "../../Common/Evento.h"

#include <iostream>
RecibidorEventos::RecibidorEventos(Socket& origen, ColaBloqueante<std::shared_ptr<Evento>>& destino, bool& seguirCorriendo, int uuid) :
    origen_(origen),
    destino_(destino),
    seguirCorriendo_(seguirCorriendo),
    uuid_(uuid) {
}

void RecibidorEventos::ejecutar() {
    while(seguirCorriendo_) {
        try {
            std::shared_ptr<Evento> eventoRecibido(serializador_.recibirEvento(origen_));
            eventoRecibido->atributos["uuid"] = uuid_;
            destino_.put(eventoRecibido);
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << '\n';
            seguirCorriendo_ = false;
        }       
    }
}

void RecibidorEventos::cerrar() {
    seguirCorriendo_ = false;
    Thread::cerrar();
}
