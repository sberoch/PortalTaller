#include "VistaObjeto.h"
#include <iostream>

void VistaObjeto::setPosInicial(int x, int y) {
	this->xInicial = x; this->yInicial = y;
}

void VistaObjeto::asignarEstado(int estado) {
	std::cout << "Asignando estado a objeto incorrecto\n";
}

void VistaObjeto::mover(int x, int y) {
	std::cout << "Intentando mover objeto incorrecto\n";
}

void VistaObjeto::flip(int flip) {
	std::cout << "Intentando flipear objeto incorrecto\n";
}

void VistaObjeto::setId(int id) {
	this->id = id;
}

int VistaObjeto::getId() {
	return id;
}