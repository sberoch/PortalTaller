#include "VistaReceptor.h"

VistaReceptor::VistaReceptor(SdlTexture& tex, int angulo) {
	this->textura = tex;
	this->angulo = angulo;
	Area srcArea(199, 0, 191, 191);
	clips.push_back(srcArea);
	tamanioHorizontal = 100;
	tamanioVertical = 100;
}

void VistaReceptor::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(xInicial + x - tamanioHorizontal/2,
				  yInicial + y - tamanioVertical/2, 
				  tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea, (double) angulo, SDL_FLIP_NONE);
}
