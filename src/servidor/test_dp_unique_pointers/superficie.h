#ifndef __SUPERFICIE_H__
#define __SUPERFICIE_H__

// Forward declaration
class SuperficieVisitor;

class Superficie {
    public:
    virtual void visitar(SuperficieVisitor& sv) = 0;

};

#endif