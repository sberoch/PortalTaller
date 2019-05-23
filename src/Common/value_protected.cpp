#include "value_protected.h"

template <typename T>
ValueProtected<T>::ValueProtected(T unValor) :
    valor_(unValor) {
}

template <typename T>
ValueProtected<T>::~ValueProtected() {
}

template <typename T>
T ValueProtected<T>::operator()() {
    std::lock_guard<std::mutex> lck(mtx);
    return valor_;
}

template <typename T>
void ValueProtected<T>::set(T unValor) {
    std::lock_guard<std::mutex> lck(mtx);
    valor_ = unValor;
}
