#ifndef MENU_H
#define MENU_H

#include "SdlWindow.h"
#include "SdlTexture.h"
#include "VistaImagenMenu.h"

class Menu {
private:
	int xScreen;
	int yScreen;
	SdlWindow window;
	SdlTexture imagenMenuTex;
	VistaImagenMenu fondo;
	bool terminado;

	Area botonJugar;
	Area botonSalir;
public:
	Menu(int xScreen, int yScreen);
	void ejecutar();
private:
	void dibujar();
	void handleEvents(SDL_Event& e);
	void asignarPosicionBotones();
};

#endif // MENU_H
