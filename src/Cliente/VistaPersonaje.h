#ifndef VISTA_PERSONAJE
#define VISTA_PERSONAJE 

#include "VistaObjetoMovil.h"
#include "AnimacionPersonaje.h"

class VistaPersonaje : public VistaObjetoMovil {
private:
	AnimacionPersonaje animaciones;
	int estado;
	SDL_RendererFlip flip;
public:
	VistaPersonaje(SdlTexture& tex);
	void dibujarEn(int x, int y);
	void mover(int x, int y);
	void asignarEstado(int estado);
	void flipDerecha();
	void flipIzquierda();
};

#endif