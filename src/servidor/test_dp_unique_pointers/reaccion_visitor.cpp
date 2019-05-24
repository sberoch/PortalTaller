#include "reaccion_visitor.h"
#include "entidad.h"

#include <iostream>

ReaccionVisitor::ReaccionVisitor(Entidad& unaEntidad) : entidad_(unaEntidad) {
}

void ReaccionVisitor::visitar(SuperficieMetal& s) {
    std::cout << "METAL PISADO \n";
    entidad_.afectarseCon(s);
}

void ReaccionVisitor::visitar(SuperficieAcido& s) {
    std::cout << "ACIDO PISADO \n";
    entidad_.afectarseCon(s);
}