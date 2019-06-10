#include "VistaTorta.h"

VistaTorta::VistaTorta(SdlTexture& tex) {
	this->textura = tex;
	Area srcArea(200, 85, 160, 135);
	clips.push_back(srcArea);
	tamanioHorizontal = 100;
	tamanioVertical = 75;
}

void VistaTorta::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(xInicial + x - tamanioHorizontal/2,
				  yInicial + y - tamanioVertical/2, 
				  tamanioHorizontal, tamanioVertical);;
	textura.render(srcArea, destArea);
}

