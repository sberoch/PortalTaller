#include "forma_bloque.h"

#include "../../server_config.h"

void FormaBloque::inicializar(b2Body* unB2Body) {
	Forma::inicializarCaja(unB2Body,
	CONFIG.SIZE_BLOQUE_DEFAULT_X,
	CONFIG.SIZE_BLOQUE_DEFAULT_Y,
	CONFIG.DENSIDAD_DEFAULT,
	false,
	false);
}

FormaBloque::~FormaBloque() {
}
