#ifndef MENU_H
#define MENU_H

#include "SdlWindow.h"
#include "SdlTexture.h"
#include "VistaFondo.h"
#include "Audio.h"
#include "Texto.h"
#include "../Common/cola_bloqueante.h"
#include "EscenaBase.h"

class Menu : public EscenaBase {
private:
	int xScreen;
	int yScreen;

	SdlWindow& window;
	SdlTexture imagenMenuTex;
	VistaFondo fondo;
	Audio audio;

	ColaBloqueante<Evento*>& colaEnviar;
	SDL_Event e;
	bool terminado;
	int siguienteEscena;

	Texto botonJugar;
	Texto botonSalir;
public:
	Menu(SdlWindow& window, ColaBloqueante<Evento*>& colaEnviar);
	virtual bool termino() override;
	virtual void actualizar() override;
	virtual void dibujar() override;
	virtual int manejarEventos() override;
	virtual void manejar(Evento& evento) {};
	virtual ~Menu() {}
private:
	void dibujarBotones();
};

#endif // MENU_H
