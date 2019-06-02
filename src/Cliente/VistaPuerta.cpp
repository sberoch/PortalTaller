#include "VistaPuerta.h"
#include "../Common/Constantes.h"

#define CANT_CLIPS 38

VistaPuerta::VistaPuerta(SdlTexture& tex) {
	frame = 0;
	this->textura = tex;
	this->estado = 0;

	//Abierta
	Area areaAbierta(1, 2052, 192, 384);
	clips.push_back(areaAbierta);
	/*
	//Abriendo
	for (int i = 0; i < 10; ++i) {
		Area area(1 + 194*i, 2052, 192, 384);
		clips.push_back(area);
	}
	for (int i = 0; i < 9; ++i) {
		Area area(1 + 194*i, 2437, 192, 384);
		clips.push_back(area);
	}
	
	//Cerrando
	for (int i = 0; i < 9; ++i) {
		Area area(1553 - i*194, 2437, 192, 384);
		clips.push_back(area);
	}
	for (int i = 0; i < 10; ++i) {
		Area area(1747 - 194*i, 2052, 192, 384);
		clips.push_back(area);
	}
	*/
	//Cerrada
	Area areaCerrada(1553, 2437, 192, 384);
	clips.push_back(areaCerrada);
	tamanioHorizontal = 85;
	tamanioVertical = 170;

}

void VistaPuerta::dibujarEn(int x, int y) {
	Area srcArea = clips.at(estado);
	Area destArea(xInicial + x, yInicial + y, tamanioHorizontal, tamanioVertical);
	textura.render(srcArea, destArea);
}


void VistaPuerta::asignarEstado(int estado) {
	if (estado == ABIERTA) this->estado = 1;
	else if (estado == CERRADA) this->estado = 0;
}