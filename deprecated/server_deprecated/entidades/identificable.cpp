#include "identificable.h"

uint16_t Identificable::contadorUUID_ = 0;

uint16_t Identificable::proximoUUID() {
    std::lock_guard<std::mutex> lck(mutex_);
    return ++contadorUUID_;
}

Identificable::Identificable() : UUID_(proximoUUID()) {
}

Identificable::~Identificable() {
}

uint16_t Identificable::uuid() {
    return UUID_;
}
