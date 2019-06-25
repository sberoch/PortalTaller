#include "colisionable.h"

void Colisionable::colisionarContra(Jugador& j) {
}

void Colisionable::colisionarContra(DisparoPortal& d) {
}

void Colisionable::colisionarContra(Roca& r) {
}

void Colisionable::colisionarContra(DisparoPin& d) {
}

void Colisionable::colisionarContra(BolaEnergia& b) {
}

void Colisionable::colisionarContra(BloqueEmisor& b) {
}

void Colisionable::colisionarContra(BloqueReceptor& b) {
}

void Colisionable::colisionarContra(BloqueMetalCuadrado& b) {
}

void Colisionable::colisionarContra(BloqueMetalTriangular& b) {
}

void Colisionable::colisionarContra(BloquePiedra& b) {
}

void Colisionable::colisionarContra(BarreraEnergia& b) {
}

void Colisionable::colisionarContra(SuperficieBoton& s) {
}

void Colisionable::colisionarContra(SuperficieCompuerta& s) {
}

void Colisionable::colisionarContra(Portal& p) {
}

Colisionable::Colisionable(Fisicas& unasFisicas) :
    fisicas_(unasFisicas),
    forma_(nullptr) {
}

Colisionable::~Colisionable() {
}

std::shared_ptr<Forma> Colisionable::forma() {
    return forma_;
}