#ifndef __REACCION_VISITOR_H__
#define __REACCION_VISITOR_H__

#include "superficie_visitor.h"

// Forward declaration
class SuperficieMetal;
class SuperficieAcido;
class Entidad;

class ReaccionVisitor : public SuperficieVisitor {
    private:
    Entidad& entidad_;
    
    public:
    explicit ReaccionVisitor(Entidad& unaEntidad);

    virtual void visitar(SuperficieMetal& s) override;

    virtual void visitar(SuperficieAcido& s) override;
};

#endif