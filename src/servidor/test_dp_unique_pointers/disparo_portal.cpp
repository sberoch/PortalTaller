#include "disparo_portal.h"
#include "reaccion_visitor.h"
#include "superficie.h"
#include "superficie_acido.h"

#include <iostream>

void DisparoPortal::afectarseCon(Superficie& s) {
    ReaccionVisitor v(*this);
    s.visitar(v);
}

void DisparoPortal::afectarseCon(SuperficieAcido& s) {
    std::cout << "Soy un disparo de portal y voy a desaparecer\n";
}

void DisparoPortal::afectarseCon(SuperficieMetal& s) {
    std::cout << "Soy un disparo de portal y voy a desaparecer, pero voy a crear un portal en el metal\n";
}