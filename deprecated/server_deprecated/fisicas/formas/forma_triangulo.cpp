#include "forma_triangulo.h"

#include "../../server_config.h"

void FormaTriangulo::inicializar(b2Body* unB2Body) {	
	Forma::inicializarTriangulo(unB2Body,
		CONFIG.SIZE_BLOQUE_DEFAULT_X,
		CONFIG.SIZE_BLOQUE_DEFAULT_Y,
        CONFIG.DENSIDAD_DEFAULT,
		false,
		false);
}

FormaTriangulo::~FormaTriangulo() {
}