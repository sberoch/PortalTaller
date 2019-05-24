#ifndef __SUPERFICIE_ACIDO_H__
#define __SUPERFICIE_ACIDO_H__

#include "superficie.h"

// Forward declaration
class SuperficieVisitor;

class SuperficieAcido : public Superficie {
    public:
    virtual void visitar(SuperficieVisitor& sv) override;
};

#endif