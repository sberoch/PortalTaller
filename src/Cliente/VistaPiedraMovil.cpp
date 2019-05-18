#include "VistaPiedraMovil.h"

#include <stdlib.h>     
#include <time.h>  

VistaPiedraMovil::VistaPiedraMovil(SdlTexture& tex) {
	this->textura = tex;
	srand(time(NULL));
	posX = 0;
	posY = 0;
	int nroPiedra = rand() % 8;
	Area srcArea(1 + nroPiedra*86, 4513, 85, 83);
	clips.push_back(srcArea);
	tamanioHorizontal = 85;
	tamanioVertical = 85;
}

void VistaPiedraMovil::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(x + posX, y + posY, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}

void VistaPiedraMovil::mover(int x, int y) {
	posX += x;
	posY += y;
}
