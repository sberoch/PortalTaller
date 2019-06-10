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
	tamanioHorizontal = 100;
	tamanioVertical = 100;
}

void VistaPiedraMovil::dibujarEn(int x, int y) {
	Area srcArea = clips.front();
	Area destArea(xInicial + x + posX - tamanioHorizontal/2,
				  yInicial + y + posY - tamanioVertical/2, 
				  tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}

void VistaPiedraMovil::mover(int x, int y) {
	posX += x;
	posY += y;
}
