#ifndef __IDENTIFICABLE_H__
#define __IDENTIFICABLE_H__

#include <cstdint>
#include <mutex>

#include "Box2D/Box2D.h"

// Forward declaration
class Fisicas;

class Identificable {
private:
    static uint16_t contadorUUID_;
    std::mutex mutex_;
    b2Body* cuerpo_;
    uint16_t proximoUUID();

protected:
    const uint16_t UUID_;

public:
    Identificable();
    virtual ~Identificable();
    uint16_t uuid();
    virtual void agregateEn(Fisicas& unasFisicas) = 0;
};

#endif
