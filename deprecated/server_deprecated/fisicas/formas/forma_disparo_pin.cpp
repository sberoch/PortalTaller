#include "forma_disparo_pin.h"

#include "../../server_config.h"

void FormaDisparoPin::inicializar(b2Body* unB2Body) {	
	Forma::inicializarCirculo(unB2Body,
		CONFIG.SIZE_RADIO_DISPARO_PIN,
		CONFIG.DENSIDAD_DEFAULT,
		false,
		false);
}

FormaDisparoPin::~FormaDisparoPin() {
}
