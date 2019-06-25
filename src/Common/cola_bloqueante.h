#include "value_protected.h"

#ifndef __COLA_CLIENTES_H__
#define __COLA_CLIENTES_H__

#include <mutex>
#include <condition_variable>
#include <queue>

// Cola protegida. Permite agregar y obtener elementos, mientras
// la cola esté activa. Para detener y desactivar la cola, debe llamarse 
// al método detener().
template <class T>
class ColaBloqueante {
    private:
    std::mutex mtx_;
    std::queue<T> elementos_;
    std::condition_variable cond_;
    ValueProtected<bool> detenida_;

    ColaBloqueante(ColaBloqueante&& otra) = delete;

    ColaBloqueante(const ColaBloqueante& otra) = delete;

    ColaBloqueante& operator=(const ColaBloqueante& otra) = delete;

    ColaBloqueante& operator=(ColaBloqueante&& otra) = delete;

    public:
    ColaBloqueante();

    ~ColaBloqueante();

    void put(T& unElemento);
    
    bool get(T& unElemento);

    void detener();

    void reiniciar();
};

#endif
