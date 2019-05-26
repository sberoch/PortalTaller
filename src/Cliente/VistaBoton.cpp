#include "VistaBoton.h"

#define CANT_CLIPS 2

VistaBoton::VistaBoton(SdlTexture& tex) {
	this->textura = tex;
	for (int i = 0; i < CANT_CLIPS; ++i) {
		Area area(1, 116 + i*76, 175, 55);
		clips.push_back(area);
	}
	tamanioHorizontal = 80;
	tamanioVertical = 25;

}

void VistaBoton::dibujarEn(int x, int y) {
	Area srcArea = clips.at(floor(frame/32));
	Area destArea(xInicial + x, yInicial + y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
	++frame;
	if (frame/32 >= CANT_CLIPS) {
		frame = 0;
	}
}