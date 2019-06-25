#include "forma_roca.h"

#include "../../server_config.h"

void FormaRoca::inicializar(b2Body* unB2Body) {	
	Forma::inicializarCirculo(unB2Body,
		CONFIG.SIZE_RADIO_ROCA,
		CONFIG.DENSIDAD_DEFAULT,
		false,
		false);
}

FormaRoca::~FormaRoca() {
}
