#ifndef __IDENTIFICABLE_H__
#define __IDENTIFICABLE_H__

#include <mutex>

class Identificable {
private:
    std::mutex mutex_;
    const int UUID_;
    static int contadorUUID_;    
    int proximoUUID();

public:
    Identificable();
    virtual ~Identificable();
    int uuid();
};

#endif
