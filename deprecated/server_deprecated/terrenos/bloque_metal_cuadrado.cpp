#include "bloque_metal_cuadrado.h"

#include "../entidades/colisionable.h"
#include "../entidades/disparo_portal.h"
#include "../fisicas/formas/forma_bloque.h"

#include <iostream>

void BloqueMetalCuadrado::colisionarContra(Colisionable& unColisionable) {
    unColisionable.colisionarContra(*this);
}

void BloqueMetalCuadrado::colisionarContra(DisparoPortal& d) {
    std::cout << "Soy bmc colisionando contra un disparo de portal\n";
}

BloqueMetalCuadrado::BloqueMetalCuadrado(Fisicas& unasFisicas) : Terreno(unasFisicas) {
    forma_ = std::shared_ptr<Forma>(new FormaBloque());
}