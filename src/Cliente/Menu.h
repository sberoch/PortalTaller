#ifndef MENU_H
#define MENU_H

#include "SdlWindow.h"
#include "SdlTexture.h"
#include "VistaFondo.h"
#include "Audio.h"
#include "../Common/Socket.h"
#include "EscenaBase.h"

class Menu : public EscenaBase {
private:
	int xScreen;
	int yScreen;
	SdlWindow& window;
	SdlTexture imagenMenuTex;
	VistaFondo fondo;
	Audio audio;

	SDL_Event e;
	bool terminado;
	int siguienteEscena;

	Area botonJugar;
	Area botonSalir;
public:
	Menu(SdlWindow& window);
	virtual bool termino() override;
	virtual void actualizar() override;
	virtual void dibujar() override;
	virtual int manejarEventos() override;
	virtual ~Menu() {}
};

#endif // MENU_H
