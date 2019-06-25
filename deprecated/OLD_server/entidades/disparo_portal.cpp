#include "disparo_portal.h"

#include "colisionable.h"
#include "../terrenos/bloque_metal_cuadrado.h"
#include "../fisicas/formas/forma_disparo_portal.h"

void DisparoPortal::colisionarContra(Colisionable& unColisionable) {
    unColisionable.colisionarContra(*this);
}

void DisparoPortal::colisionarContra(BloqueMetalCuadrado& b) {
    fisicas_.destruir(*this);
}

DisparoPortal::DisparoPortal(Fisicas& unasFisicas) :
    Entidad(unasFisicas) {
    forma_ = std::shared_ptr<Forma>(new FormaDisparoPortal());
}

DisparoPortal::~DisparoPortal() {
}