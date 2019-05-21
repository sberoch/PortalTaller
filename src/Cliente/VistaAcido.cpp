#include "VistaAcido.h"

#define CANT_CLIPS 8

VistaAcido::VistaAcido(SdlTexture& tex) {
	this->textura = tex;
	for (int i = 0; i < CANT_CLIPS; ++i) {
		Area area(i*301, 1545, 301, 60);
		clips.push_back(area);
	}
	tamanioHorizontal = 85;
	tamanioVertical = 18;
}

void VistaAcido::dibujarEn(int x, int y) {
	Area srcArea = clips.at(floor(frame/16));
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
	++frame;
	if (frame/16 >= CANT_CLIPS) {
		frame = 0;
	}
}
