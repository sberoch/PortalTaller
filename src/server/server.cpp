#include "server.h"

#include <iostream>

#include "red/aceptador.h"

#include "../Common/value_protected.h"


Servidor::Servidor(const std::string& unPuerto) :
    sktAceptador_(HOST, unPuerto) {
}

void Servidor::correr() {
    ValueProtected<bool> seguirCorriendo(true);
    Aceptador aceptador(sktAceptador_, seguirCorriendo, *this);
    aceptador.start();
    char c;
    while ((c = std::cin.get()) != CONDICION_SALIR) {
        // pass
    }
    seguirCorriendo.set(false);
    sktAceptador_.cerrar();
    aceptador.join();
}

void Servidor::manejar(Evento& unEvento) {
    
}
