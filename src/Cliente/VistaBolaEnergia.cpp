#include "VistaBolaEnergia.h"

#define CANT_CLIPS 3

VistaBolaEnergia::VistaBolaEnergia(SdlTexture& tex, int angulo) {
	this->textura = tex;
	this->angulo = angulo;
	frame = 0;
	posX = 0;
	posY = 0;
	for (int i = 0; i < CANT_CLIPS; ++i) {
		Area area(i*110, 1896, 110, 110);
		clips.push_back(area);
	}
	tamanioHorizontal = 100;
	tamanioVertical = 100;
}

void VistaBolaEnergia::dibujarEn(int x, int y) {
	Area srcArea = clips.at(floor(frame/4));
	Area destArea(xInicial + x + posX - tamanioHorizontal/2,
				  yInicial + y + posY - tamanioVertical/2, 
				  tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea, (double) angulo, SDL_FLIP_NONE);
	++frame;
	if ((frame/4) >= CANT_CLIPS) {
		frame = 0;
	}
}

void VistaBolaEnergia::mover(int x, int y) {
	posX += x;
	posY += y;
}

void VistaBolaEnergia::asignarRotacion(int rotacion) {
	angulo = rotacion;
}
