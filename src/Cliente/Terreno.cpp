#include "Terreno.h"

#include <iostream>

#include "SdlTexture.h"
#include "VistaBloqueMetal.h"
#include "VistaBloquePiedra.h"

Terreno::Terreno(const SdlWindow& window) :
	bloqueTex("bloque_metal_diag.png", window) {
	x = 0;
	y = 0;
	VistaBloquePiedra* piedra = new VistaBloquePiedra(bloqueTex);
	objetosDelTerreno.push_back(piedra);
}

void Terreno::actualizar(int deltaX, int deltaY) {
	x += deltaX; y += deltaY;
	VistaObjeto* obj = objetosDelTerreno.at(0);
	obj->dibujarEn(600 + x, 600 + y);
}

Terreno::~Terreno() {

}