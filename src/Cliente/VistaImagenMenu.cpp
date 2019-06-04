#include "VistaImagenMenu.h"

#include <iostream>

VistaImagenMenu::VistaImagenMenu(const SdlTexture& tex) {
	this->textura = tex;
	Area srcArea(0, 0, 1680, 1050);
	clips.push_back(srcArea);
	tamanioHorizontal = 0;
	tamanioVertical = 0;
}

void VistaImagenMenu::setDimensiones(int x, int y) {
	tamanioHorizontal = x;
	tamanioVertical = y;
}

void VistaImagenMenu::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(x, y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}

