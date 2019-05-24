#include "superficie_acido.h"
#include "superficie_visitor.h"

void SuperficieAcido::visitar(SuperficieVisitor& sv) {
    sv.visitar(*this);
}