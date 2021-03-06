#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include <SDL2/SDL.h>
#include "SdlWindow.h"
#include "../Common/Constantes.h"
#include "../Common/cola_bloqueante.h"
#include "Audio.h"
#include "../Common/Conversor.h"

class Evento;

class InputHandler {
private:
	SdlWindow& window;
	ColaBloqueante<Evento*>& colaEnviar;
	Audio& audio;
	Conversor conv;

	SDL_Event event;
	int playerId;
	bool terminado;
	bool ctrl;
	bool fullscreen;
public:
	InputHandler(SdlWindow& window, ColaBloqueante<Evento*>& colaEnviar, Audio& audio);
	void setPlayerId(int playerId);
	bool termino();
	void handle(int cantObjetosEnJuego);
};

#endif // INPUT_HANDLER_H
