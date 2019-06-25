#include "forma_disparo_portal.h"

#include "../../server_config.h"

void FormaDisparoPortal::inicializar(b2Body* unB2Body) {	
	Forma::inicializarCirculo(unB2Body,
		CONFIG.SIZE_RADIO_DISPARO_PORTAL,
		CONFIG.DENSIDAD_DEFAULT,
		false,
		false);
}

FormaDisparoPortal::~FormaDisparoPortal() {
}
