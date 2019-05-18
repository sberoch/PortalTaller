#include "VistaBolaEnergia.h"

#define CANT_CLIPS 3

VistaBolaEnergia::VistaBolaEnergia(SdlTexture& tex) {
	this->textura = tex;
	frame = 0;
	posX = 0;
	posY = 0;
	for (int i = 0; i < CANT_CLIPS; ++i) {
		Area area(i*115, 1922, 115, 60);
		clips.push_back(area);
	}
	tamanioHorizontal = 85;
	tamanioVertical = 40;
}

void VistaBolaEnergia::dibujarEn(int x, int y) {
	Area srcArea = clips.at(floor(frame/8));
	Area destArea(posX + x, posY + y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
	++frame;
	if ((frame/8) >= CANT_CLIPS) {
		frame = 0;
	}
}

void VistaBolaEnergia::mover(int x, int y) {
	posX += x;
	posY += y;
}
