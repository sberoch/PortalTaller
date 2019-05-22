#include "VistaTorta.h"

VistaTorta::VistaTorta(SdlTexture& tex) {
	this->textura = tex;
	Area srcArea(200, 85, 160, 135);
	clips.push_back(srcArea);
	tamanioHorizontal = 85;
	tamanioVertical = 65;
}

void VistaTorta::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}

