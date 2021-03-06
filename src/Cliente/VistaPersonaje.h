#ifndef VISTA_PERSONAJE
#define VISTA_PERSONAJE 

#include "VistaObjetoMovil.h"
#include "AnimacionPersonaje.h"
#include "Audio.h"

class VistaPersonaje : public VistaObjetoMovil {
private:
	Audio audio;
	AnimacionPersonaje animaciones;
	int estado;
	SDL_RendererFlip rendererFlip;
public:
	VistaPersonaje(SdlTexture& tex);
	void dibujarEn(int x, int y);
	virtual void mover(int x, int y) override;
	virtual void asignarEstado(int estado) override;
	virtual void flip(int flip) override;
	virtual ~VistaPersonaje() {}
private:
	void siguienteFrame(int cantClips);
};

#endif