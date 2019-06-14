#include "VistaAcido.h"

#define CANT_CLIPS 8

VistaAcido::VistaAcido(SdlTexture& tex) {
	this->textura = tex;
	frame = 0;
	for (int i = 0; i < CANT_CLIPS; ++i) {
		Area area(i*300, 1307, 300, 300);
		clips.push_back(area);
	}
	tamanioHorizontal = 100;
	tamanioVertical = 100;
}

void VistaAcido::dibujarEn(int x, int y) {
	Area srcArea = clips.at(floor(frame/4));
	Area destArea(xInicial + x - tamanioHorizontal/2,
				  yInicial + y - tamanioVertical/2 + 10, //Dibujo 10 pixeles mas abajo para que se vea mejor  
				  tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
	++frame;
	if (frame/4 >= CANT_CLIPS) {
		frame = 0;
	}
}
