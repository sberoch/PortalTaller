#include "VistaPersonaje.h"
#include <iostream>

VistaPersonaje::VistaPersonaje(SdlTexture& tex) {
	this->textura = tex;
	frame = 0;
	posX = 0;
	posY = 0;
	tamanioVertical = 105;
	estado = 0;
	flip = SDL_FLIP_NONE;
}

void VistaPersonaje::dibujarEn(int x, int y) {
	Area srcArea = animaciones.obtenerConEstado(estado, floor(frame/8));
	tamanioHorizontal = int(srcArea.getWidth()/2);
	Area destArea(posX + x, posY + y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea, 0.0, flip);

	++frame;
	if ((frame/8) >= animaciones.size()) { 
		frame = 0;
		if (estado == 2) {
			estado = 0;
		}
	}
}

void VistaPersonaje::mover(int x, int y) {
	posX += x;
	posY += y;
}

void VistaPersonaje::asignarEstado(int estado) {
	if (estado != this->estado) {
		frame = 0;
	}
	this->estado = estado;
}

void VistaPersonaje::flipDerecha() {
	flip = SDL_FLIP_NONE; 	
}

void VistaPersonaje::flipIzquierda() {
	flip = SDL_FLIP_HORIZONTAL;
}