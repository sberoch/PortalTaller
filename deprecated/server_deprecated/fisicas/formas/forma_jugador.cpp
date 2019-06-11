#include "forma_jugador.h"

#include "../../server_config.h"

void FormaJugador::inicializar(b2Body* unB2Body) {	
	Forma::inicializarCaja(unB2Body,
		CONFIG.SIZE_JUGADOR_X,
		CONFIG.SIZE_JUGADOR_Y,
		CONFIG.DENSIDAD_DEFAULT,
		false,
		false);
}

FormaJugador::~FormaJugador() {
}
