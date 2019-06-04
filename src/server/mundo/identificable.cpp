#include "identificable.h"

int Identificable::contadorUUID_ = 0;

int Identificable::proximoUUID() {
    std::lock_guard<std::mutex> lck(mutex_);
    return ++contadorUUID_;
}

Identificable::Identificable() : UUID_(proximoUUID()) {
}

Identificable::~Identificable() {
}

int Identificable::uuid() {
    return UUID_;
}
