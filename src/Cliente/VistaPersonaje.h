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
	virtual void mover(int x, int y) override;
	virtual void asignarEstado(int estado) override;
	void flipDerecha();
	void flipIzquierda();
};

#endif