#include "server.h"

#include <iostream>

#include "red/aceptador.h"
#include "red/sala_de_espera.h"
#include "red/coordinador_partidas.h"

#include "server_config.h"

#include <iostream>
Servidor::Servidor(const std::string& unPuerto) {
    sktAceptador_.vincularYEscuchar(unPuerto.c_str(), CONFIG.MAX_EN_ESPERA);
}

void Servidor::correr() {
    bool seguirCorriendo = true;
    CoordinadorPartidas coordinadorPartidas(seguirCorriendo);
    coordinadorPartidas.iniciar();    
    SalaDeEspera salaDeEspera(seguirCorriendo, coordinadorPartidas);
    salaDeEspera.iniciar();
    Aceptador aceptador(sktAceptador_, seguirCorriendo, *this, salaDeEspera);
    aceptador.iniciar();
    char c;
    while ((c = std::cin.get()) != CONDICION_SALIR) {
        // pass
    }
    seguirCorriendo = false;
    sktAceptador_.shutdown();
    aceptador.cerrar();
    salaDeEspera.cerrar();
    //coordinadorPartidas.cerrar();
}
