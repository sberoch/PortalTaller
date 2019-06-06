#include "Conversor.h"
#include <cmath>

Conversor::Conversor(int pixelesPorBloque) : 
	pixelesPorBloque(pixelesPorBloque) {}

int Conversor::bloqueAPixel(int coord) {
	return round((pixelesPorBloque*coord) + pixelesPorBloque/2);
}

int Conversor::pixelABloque(int coord) {
	return round((coord - pixelesPorBloque/2) / pixelesPorBloque);
}