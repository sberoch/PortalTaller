#include "Escena.h"
#include "EnviadorEventos.h"
#include "RecibidorEventos.h"

int main(int argc, char** argv) {
	Escena escena(1000,800);

	RecibidorEventos recibidorEventos;
	EnviadorEventos enviadorEventos;
	recibidorEventos.iniciar();
	enviadorEventos.iniciar();

	//Crear mapa desde yaml
 
	while(!escena.termino()) {
		escena.recibirCambios();
		escena.actualizar();	
		escena.manejarEventos();   
	}

	recibidorEventos.cerrar();
	enviadorEventos.cerrar();
	return 0;
}
