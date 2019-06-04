#include "VistaBoton.h"
#include "../Common/Constantes.h"

#define CANT_CLIPS 2

VistaBoton::VistaBoton(SdlTexture& tex) {
	this->textura = tex;
	this->estado = 0;
	for (int i = 0; i < CANT_CLIPS; ++i) {
		Area area(1, 116 + i*76, 175, 55);
		clips.push_back(area);
	}
	tamanioHorizontal = 100;
	tamanioVertical = 30;

}

void VistaBoton::dibujarEn(int x, int y) {
	Area srcArea = clips.at(estado);
	Area destArea(xInicial + x, yInicial + y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}

void VistaBoton::asignarEstado(int estado) {
	if (estado == PRESIONADO) this->estado = 1;
	else if (estado == NO_PRESIONADO) this->estado = 0;
}