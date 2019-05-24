#ifndef __SUPERFICIE_METAL_H__
#define __SUPERFICIE_METAL_H__

#include "superficie.h"

// Forward declaration
class SuperficieVisitor;

class SuperficieMetal : public Superficie {
    public:
    virtual void visitar(SuperficieVisitor& sv) override;
};

#endif