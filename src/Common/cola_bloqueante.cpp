#include "cola_bloqueante.h"
#include "Evento.h"

#include <memory>

template <class T>
ColaBloqueante<T>::ColaBloqueante() :
    detenida_(false) {
}
template <class T>
ColaBloqueante<T>::~ColaBloqueante() {
}

template <class T>
void ColaBloqueante<T>::put(T& unElemento) {
    std::lock_guard<std::mutex> lck(mtx_);
    elementos_.push(std::move(unElemento));
    cond_.notify_one();
}

template <class T>
bool ColaBloqueante<T>::get(T& unElemento) {
    std::unique_lock<std::mutex> lck(mtx_);
    cond_.wait(lck, [this]{return !elementos_.empty() || detenida_() ;});
    if (detenida_()) {
        return false;
    }
    unElemento = std::move(elementos_.front());
    elementos_.pop();
    return true;
}

template <class T>
void ColaBloqueante<T>::detener() {
    detenida_.set(true);
    cond_.notify_all();
}

template <class T>
void ColaBloqueante<T>::reiniciar() {
    detenida_.set(false);
    cond_.notify_all();
}

template class ColaBloqueante<Evento*>;
template class ColaBloqueante<std::shared_ptr<Evento>>;
