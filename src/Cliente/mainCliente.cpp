#include "Escena.h"
#include "EnviadorEventos.h"
#include "RecibidorEventos.h"

#include "../Common/cola_bloqueante.h"
#include"../Common/Cola.h"
#include "../Common/Evento.h"

#include <iostream>

int main(int argc, char** argv) {

	Escena escena(1000, 800);

	RecibidorEventos recibidorEventos;
	EnviadorEventos enviadorEventos;
	recibidorEventos.iniciar();
	enviadorEventos.iniciar();
 
	while(!escena.termino()) {
		escena.recibirCambios();
		escena.actualizar();
		escena.manejarEventos();
	}

	recibidorEventos.cerrar();
	enviadorEventos.cerrar();
	return 0;
}
