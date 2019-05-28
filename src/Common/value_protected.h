#ifndef __VALUE_H__
#define __VALUE_H__

#include <mutex>

template <typename T>
class ValueProtected {
private:
    T valor_;
    std::mutex mtx;
    ValueProtected(const ValueProtected& otro) = delete;
    ValueProtected(ValueProtected&& otro) = delete;
    ValueProtected& operator=(const ValueProtected& otro) = delete;
    ValueProtected& operator=(ValueProtected&& otro) = delete;
    
public:
    explicit ValueProtected(T unValor);
    ~ValueProtected();
    T operator()();
    void set(T unValor);
};

#endif
