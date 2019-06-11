#ifndef SELECCIONADOR_ESCENA_H
#define SELECCIONADOR_ESCENA_H

#include "SdlWindow.h"
#include "../Common/Cola.h"
#include "../Common/cola_bloqueante.h"
#include "EnviadorEventos.h"
#include "RecibidorEventos.h"
#include "../Common/Evento.h"
#include <map>

class SeleccionadorEscena {
private:
	SdlWindow window;
	Socket socket;

	ColaBloqueante<Evento*> colaEnviar;
	Cola<Evento*> colaRecibir;

	RecibidorEventos recibidorEventos; 
	EnviadorEventos enviadorEventos;

	std::map<int, EscenaBase*> escenas;
	int escenaActual;
public:
	SeleccionadorEscena(int xScreen, int yScreen);
	void ejecutar();
	~SeleccionadorEscena();
};

#endif // SELECCIONADOR_ESCENA_H
