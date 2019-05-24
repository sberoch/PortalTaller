#ifndef __SUPERFICIE_VISITOR_H__
#define __SUPERFICIE_VISITOR_H__

// Forward declaration
class SuperficieMetal;
class SuperficieAcido;

class SuperficieVisitor {
    public:
    virtual void visitar(SuperficieMetal& s) = 0;
    virtual void visitar(SuperficieAcido& s) = 0;
};

#endif