#ifndef ESCENA_SALA_H
#define ESCENA_SALA_H

#include "EscenaBase.h"
#include "SdlWindow.h"
#include "SdlTexture.h"
#include "VistaFondo.h"
#include "../Common/Cola.h"
#include "../Common/cola_bloqueante.h"
#include "../Common/Evento.h"
#include "Texto.h"
#include "Audio.h"
#include <vector>
#include <map>

class Evento;
class EventoActualizacionSala;

class EscenaSala : public EscenaBase {
private:
	int xScreen, yScreen;
	bool terminado;

	SdlWindow& window;
	SdlTexture fondoTex;
	VistaFondo fondo;
	Audio audio;

	SDL_Event e;
	int siguienteEscena;

	ColaBloqueante<Evento*>& colaEnviar;
	Cola<Evento*>& colaRecibir; 

	Texto botonUnirse;
	Texto botonCrear;
	Texto botonJugar;
	std::vector<Texto*> partidasTextos;
	std::vector<Texto*> jugadoresTextos;
	
	int cantidadPartidas;
	std::vector<int> jugadores;
	int partidaSeleccionada;
public:
	EscenaSala(SdlWindow& window, ColaBloqueante<Evento*>& colaEnviar, 
		Cola<Evento*>& colaRecibir);
	virtual bool termino() override;
	virtual void actualizar() override;
	virtual void dibujar() override;
	virtual int manejarEventos() override;
	virtual ~EscenaSala();

	virtual void manejar(Evento& evento) override;
	virtual void manejar(EventoActualizacionSala& evento) override;
private:
	void dibujarBotones();
	void cargarTextosPartidasYJugadores();
	void dibujarPartidas();
	void dibujarJugadoresEnPartida();
	bool clickEnAlgunaPartida(int x, int y);
};

#endif // ESCENA_SALA_H
