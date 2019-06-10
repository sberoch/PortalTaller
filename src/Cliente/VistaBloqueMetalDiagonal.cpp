#include "VistaBloqueMetalDiagonal.h"

VistaBloqueMetalDiagonal::VistaBloqueMetalDiagonal(SdlTexture& tex, int angulo) {
	this->textura = tex;
	this->angulo = angulo;
	Area srcArea(2, 405, 185, 185);
	clips.push_back(srcArea);
	tamanioHorizontal = 100;
	tamanioVertical = 100;
}

void VistaBloqueMetalDiagonal::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(xInicial + x - tamanioHorizontal/2,
				  yInicial + y - tamanioVertical/2, 
				  tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea, (double) angulo, SDL_FLIP_NONE);
}
