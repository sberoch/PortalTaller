#include "VistaPersonaje.h"
#include "../Common/Constantes.h"
#include <iostream>

VistaPersonaje::VistaPersonaje(SdlTexture& tex) {
	this->textura = tex;
	frame = 0;
	posX = 0;
	posY = 0;
	tamanioVertical = 105;
	estado = 0;
	rendererFlip = SDL_FLIP_NONE;
}

void VistaPersonaje::dibujarEn(int x, int y) {
	Area srcArea = animaciones.obtenerConEstado(estado, floor(frame/4));
	tamanioHorizontal = int(srcArea.getWidth()/2);
	Area destArea(xInicial + x + posX - tamanioHorizontal/2,
				  yInicial + y + posY - tamanioVertical/2, 
				  tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea, 0.0, rendererFlip);

	++frame;
	if ((frame/4) >= animaciones.size()) { 
		frame = 0;
	}
}

void VistaPersonaje::mover(int x, int y) {
	posX += x;
	posY += y;
}

void VistaPersonaje::asignarEstado(int estado) {
	if (estado != this->estado) {
		frame = 0;
		if (estado == ESTADO_MUERTO) audio.reproducirEfecto(EFECTO_MUERTE);
		else if (estado == ESTADO_SALTANDO) audio.reproducirEfecto(EFECTO_SALTO);
	}
	this->estado = estado;
}

void VistaPersonaje::flip(int flip) {
	if (flip == DERECHA) rendererFlip = SDL_FLIP_NONE;
	else if (flip == IZQUIERDA) rendererFlip = SDL_FLIP_HORIZONTAL;
}