#include "jugador.h"
#include "reaccion_visitor.h"
#include "superficie.h"
#include "superficie_acido.h"

#include <iostream>

void Jugador::afectarseCon(Superficie& s) {
    ReaccionVisitor v(*this);
    s.visitar(v);
}

void Jugador::afectarseCon(SuperficieAcido& s) {
    std::cout << "Soy un jugador y voy a morir.\n";
}