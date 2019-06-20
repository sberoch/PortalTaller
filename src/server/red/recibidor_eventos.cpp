#include "recibidor_eventos.h"

#include "../../Common/Evento.h"

RecibidorEventos::RecibidorEventos(Socket& origen, ColaBloqueante<std::shared_ptr<Evento>>& destino) :
    origen_(origen),
    destino_(destino),
    finalizado_(false) {
}

void RecibidorEventos::ejecutar() {
    while(!finalizado_) {
        std::shared_ptr<Evento> eventoRecibido(serializador_.recibirEvento(origen_));
        destino_.put(eventoRecibido);
    }
}

void RecibidorEventos::detener() {
    finalizado_ = true;
    Thread::cerrar();
}
