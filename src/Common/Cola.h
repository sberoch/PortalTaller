#ifndef COLA
#define COLA 

#include <queue>

template <class T>
class Cola {
private:
	std::queue<T> elementos;
public:
	Cola() = default;
	void push(T elem);
	T pop();
};

#endif