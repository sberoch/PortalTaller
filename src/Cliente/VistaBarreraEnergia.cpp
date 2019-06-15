#include "VistaBarreraEnergia.h"

VistaBarreraEnergia::VistaBarreraEnergia(SdlTexture& tex, int angulo) {
	this->textura = tex;
	this->angulo = angulo;
	Area srcArea(25, 1692, 100, 100);
	clips.push_back(srcArea);
	tamanioHorizontal = 100;
	tamanioVertical = 100;
}

void VistaBarreraEnergia::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(xInicial + x - tamanioHorizontal/2,
				  yInicial + y - tamanioVertical/2, 
				  tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea, (double) angulo, SDL_FLIP_NONE);
}
