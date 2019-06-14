#include "Texto.h"
#include <iostream>

Texto::Texto(const std::string textoStr,
			const int size, const SdlWindow& window) :
	texture(textoStr, size, window) {
		x = 0; y = 0;
		w = texture.getWidth();
		h = texture.getHeight();
	}

void Texto::dibujarEn(int x, int y) {
	this->x = x - w/2;
	this->y = y - h/2;
	texture.renderText(x - w/2, y - h/2);
}

bool Texto::estaCursorAdentro(int x, int y) {
	Area areaTexto(this->x, this->y, this->w, this->h);
	return areaTexto.estaAdentro(x, y);
}

void Texto::setSeleccionado(bool seleccionado) {
	if (seleccionado) texture.setColor(255,255,255);
	else texture.setColor(160,160,160);
}
