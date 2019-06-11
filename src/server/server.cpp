#include "server.h"

#include <iostream>

#include "red/aceptador.h"

#include "../Common/value_protected.h"
#include "server_config.h"


Servidor::Servidor(const std::string& unPuerto) {
    sktAceptador_.vincularYEscuchar(unPuerto.c_str(), CONFIG.MAX_EN_ESPERA);
}

void Servidor::correr() {
    ValueProtected<bool> seguirCorriendo(true);
    Aceptador aceptador(sktAceptador_, seguirCorriendo, *this);
    aceptador.iniciar();
    char c;
    while ((c = std::cin.get()) != CONDICION_SALIR) {
        // pass
    }
    seguirCorriendo.set(false);
    sktAceptador_.shutdown();
    aceptador.cerrar();
}

void Servidor::manejar(Evento& unEvento) {
    
}
