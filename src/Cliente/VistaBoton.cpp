#include "VistaBoton.h"
#include "../Common/Constantes.h"

#define CANT_CLIPS 2

VistaBoton::VistaBoton(SdlTexture& tex) {
	this->textura = tex;
	this->estado = 1;
	for (int i = 0; i < CANT_CLIPS; ++i) {
		Area area(i*200, 150, 187, 274);
		clips.push_back(area);
	}
	tamanioHorizontal = 100;
	tamanioVertical = 100;

}

void VistaBoton::dibujarEn(int x, int y) {
	Area srcArea = clips.at(estado);
	Area destArea(xInicial + x - tamanioHorizontal/2,
				  yInicial + y - tamanioVertical/2 + 3, //3 pixeles abajo para que se vea mejor 
				  tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}

void VistaBoton::asignarEstado(int estado) {
	if (estado == PRESIONADO) this->estado = 0;
	else if (estado == NO_PRESIONADO) this->estado = 1;
}