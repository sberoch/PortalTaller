#include "server.h"

#include <iostream>

#include "red/aceptador.h"

#include "server_config.h"

#include <iostream>
Servidor::Servidor(const std::string& unPuerto) {
    sktAceptador_.vincularYEscuchar(unPuerto.c_str(), CONFIG.MAX_EN_ESPERA);
}

void Servidor::correr() {
    bool seguirCorriendo = true;
    Aceptador aceptador(sktAceptador_, seguirCorriendo, *this, salaDeEspera_);
    aceptador.iniciar();
    char c;
    while ((c = std::cin.get()) != CONDICION_SALIR) {
        // pass
    }
    seguirCorriendo = false;
    sktAceptador_.shutdown();
    aceptador.cerrar();
}
