#include "Escena.h"
#include "EnviadorEventos.h"
#include "RecibidorEventos.h"
#include "SdlWindow.h"

#include "Menu.h"

#include "../Common/Evento.h"
#include "Audio.h"

#include <iostream>

int main(int argc, char** argv) {

	Menu menu(1000, 800);
	menu.ejecutar();

	/*ColaBloqueante<Evento*> colaEnviar;
	Cola<Evento*> colaRecibir;

	SdlWindow window(1000, 800);
	Escena escena(window, colaEnviar, colaRecibir);

	RecibidorEventos recibidorEventos(colaRecibir); //Anda bien, pero no usar hasta no tener los socket, come 100% cpu sino (while true)
	EnviadorEventos enviadorEventos(colaEnviar);
	recibidorEventos.iniciar();
	enviadorEventos.iniciar();
 
	while(!escena.termino()) {
		escena.recibirCambios();
		escena.actualizar();
		escena.manejarEventos();
	}

	recibidorEventos.detener();
	enviadorEventos.detener();*/

	return 0;
}
