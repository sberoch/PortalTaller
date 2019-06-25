#ifndef __IDENTIFICABLE_H__
#define __IDENTIFICABLE_H__

#include <cstdint>
#include <mutex>

class Identificable {
private:
    std::mutex mutex_;
    const uint32_t UUID_;
    static uint32_t contadorUUID_;    
    uint32_t proximoUUID();

public:
    Identificable();
    virtual ~Identificable();
    uint32_t uuid();
};

#endif
