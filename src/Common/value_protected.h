#ifndef __VALUE_H__
#define __VALUE_H__

#include <mutex>

class ValueProtected {
    private:
    bool valor_;
    std::mutex mtx;

    ValueProtected(const ValueProtected& otro) = delete;

    ValueProtected(ValueProtected&& otro) = delete;

    ValueProtected& operator=(const ValueProtected& otro) = delete;
    
    ValueProtected& operator=(ValueProtected&& otro) = delete;
    
    public:
    explicit ValueProtected(bool unValor);

    ~ValueProtected();
    
    bool operator()();
    
    void set(bool unValor);
};



ValueProtected::ValueProtected(bool unValor) :
    valor_(unValor) {
}

ValueProtected::~ValueProtected() {
}

bool ValueProtected::operator()() {
    std::lock_guard<std::mutex> lck(mtx);
    return valor_;
}

void ValueProtected::set(bool unValor) {
    std::lock_guard<std::mutex> lck(mtx);
    valor_ = unValor;
}

#endif
