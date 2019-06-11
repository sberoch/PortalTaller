#include "forma_portal.h"

#include "../../server_config.h"

void FormaPortal::inicializar(b2Body* unB2Body) {	
	Forma::inicializarCaja(unB2Body,
	CONFIG.SIZE_PORTAL_X,
	CONFIG.SIZE_PORTAL_Y,
	CONFIG.DENSIDAD_DEFAULT,
	true,
	false);
}

FormaPortal::~FormaPortal() {
}