#include "forma_boton.h"

#include "../../server_config.h"

void FormaBoton::inicializar(b2Body* unB2Body) {	
	Forma::inicializarCaja(unB2Body,
		CONFIG.SIZE_BLOQUE_DEFAULT_X,
		CONFIG.SIZE_BLOQUE_DEFAULT_Y,
        CONFIG.DENSIDAD_DEFAULT,
		true,
		false);
}

FormaBoton::~FormaBoton() {
}
