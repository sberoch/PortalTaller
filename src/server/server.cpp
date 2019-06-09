#include "server.h"

#include <iostream>

#include "../Common/value_protected.h"


Servidor::Servidor(const std::string& unPuerto) :
    sktAceptador_(HOST, unPuerto) {
}

void Servidor::correr() {
    ValueProtected<bool> seguirCorriendo(true);
    char c;
    while ((c = std::cin.get()) != CONDICION_SALIR) {
        // pass
    }
    seguirCorriendo.set(false);
    sktAceptador_.cerrar();
}

void Servidor::manejar(Evento& unEvento) {
    
}
