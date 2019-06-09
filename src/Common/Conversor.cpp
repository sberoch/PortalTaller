#include "Conversor.h"
#include <cmath>
#include <iostream>

Conversor::Conversor(int pixelesPorBloque) : 
	pixelesPorBloque(pixelesPorBloque) {}

int Conversor::bloqueAPixel(float coord) {
	return round((pixelesPorBloque*coord) + pixelesPorBloque/2);
}

float Conversor::pixelABloque(int coord) {
	return ((float) (coord - pixelesPorBloque/2) / pixelesPorBloque);
}