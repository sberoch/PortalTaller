#include "VistaPuerta.h"
#include "../Common/Constantes.h"

#define CANT_CLIPS 38

VistaPuerta::VistaPuerta(SdlTexture& tex) {
	frame = 19;
	this->textura = tex;
	this->estado = 1;
	
	//Abriendo
	for (int i = 0; i < 10; ++i) {
		Area area(1 + 194*i, 2052, 192, 384);
		clips.push_back(area);
	}
	for (int i = 0; i < 9; ++i) {
		Area area(1 + 194*i, 2437, 192, 384);
		clips.push_back(area);
	}

	//Abierta
	Area areaAbierta(1553, 2437, 192, 384);
	clips.push_back(areaAbierta);
	
	//Cerrando
	for (int i = 0; i < 9; ++i) {
		Area area(1553 - i*194, 2437, 192, 384);
		clips.push_back(area);
	}
	for (int i = 0; i < 10; ++i) {
		Area area(1747 - 194*i, 2052, 192, 384);
		clips.push_back(area);
	}
	
	//Cerrada
	Area areaCerrada(1, 2052, 192, 384);
	clips.push_back(areaCerrada);
	tamanioHorizontal = 100;
	tamanioVertical = 200;

}

void VistaPuerta::dibujarEn(int x, int y) {
	Area srcArea = clips.at(estado*20 + frame);
	Area destArea(xInicial + x - tamanioHorizontal/2,
				  yInicial + y - tamanioVertical/2 - tamanioVertical/4, 
				  tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
	if (frame < 19) {
		frame++;
	}
}


void VistaPuerta::asignarEstado(int estado) {
	if (estado == ABIERTA) {
		this->estado = 0;
	} else if (estado == CERRADA) {
		this->estado = 1;
	}
	frame = 0;
	audio.reproducirEfecto(EFECTO_PUERTA);
}