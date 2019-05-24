#include "superficie_visitor.h"
#include "superficie_metal.h"

void SuperficieMetal::visitar(SuperficieVisitor& sv) {
    sv.visitar(*this);
}