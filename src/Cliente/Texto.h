#ifndef TEXTO_H
#define TEXTO_H

#include "SdlTextureTexto.h"
#include "Area.h"

class Texto {
private:
	SdlTextureTexto texture;
	int x, y, w, h;
public:
	Texto(const std::string textoStr, const int size, const SdlWindow& window);
	void dibujarEn(int x, int y);
	bool estaCursorAdentro(int x, int y);
	void setSeleccionado(bool seleccionado);
};

#endif // TEXTO_H
