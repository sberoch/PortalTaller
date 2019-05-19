#include "VistaPersonaje.h"

VistaPersonaje::VistaPersonaje(SdlTexture& tex) {
	this->textura = tex;
	frame = 0;
	posX = 0;
	posY = 0;
	tamanioVertical = 215;
	estado = 0;
	flip = SDL_FLIP_NONE;
}

void VistaPersonaje::dibujarEn(int x, int y) {
	std::vector<Area> clips = animaciones.obtenerConEstado(estado);
	tamanioHorizontal = clips.front().getWidth();

	//TODO: crashea con esto cuando hago cambio de estado de tal forma que
	// quedan frames prohibidos de la animacion con menos frames
	Area srcArea = clips.at(floor(frame/8));
	Area destArea(posX + x, posY + y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea, flip);

	++frame;
	if ((frame/8) >= clips.size()) { 4 
		frame = 0;
	}
}

void VistaPersonaje::mover(int x, int y) {
	posX += x;
	posY += y;
}

void VistaPersonaje::asignarEstado(int estado) {
	this->estado = estado;
}

void VistaPersonaje::flipDerecha() {
	flip = SDL_FLIP_NONE; 	
}

void VistaPersonaje::flipIzquierda() {
	flip = SDL_FLIP_HORIZONTAL;
}