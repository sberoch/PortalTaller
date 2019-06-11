#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

//No poner por ahora en CMakeLists.txt, por alguna razon crashea

#include <SDL2/SDL.h>
#include <map>
#include <cstdint>
#include "../Common/Constantes.h"
#include "../Common/cola_bloqueante.h"

class Evento;

class InputHandler {
private:
	ColaBloqueante<Evento*>& colaEnviar;
	int playerId;
	bool terminado;
	SDL_Event event;
	bool ctrl;

	std::map<int, Evento*> eventosTeclado;
	std::map<uint8_t, Evento*> eventosMouse;
public:
	InputHandler(ColaBloqueante<Evento*>& colaEnviar);
	void setPlayerId(int playerId);
	bool termino();
	void handle();
private:
	bool esKeyDown(SDL_Event event) const;
	bool esKeyUp(SDL_Event event) const;
	bool esMouse(SDL_Event event) const;
	void handleTeclado(int button);
	void handleMouse(uint8_t button);
};

#endif // INPUT_HANDLER_H