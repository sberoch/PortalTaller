#include "forma_bola_energia.h"

#include "../../server_config.h"

void FormaBolaEnergia::inicializar(b2Body* unB2Body) {	
	Forma::inicializarCirculo(unB2Body,
		CONFIG.SIZE_RADIO_BOLA_ENERGIA,
		CONFIG.DENSIDAD_DEFAULT,
		false,
		false);
}

FormaBolaEnergia::~FormaBolaEnergia() {
}
