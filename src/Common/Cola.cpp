#include "Cola.h"

template<class T>
void Cola<T>::push(T elem) {
	elementos.push(elem);
}

template<class T>
T Cola<T>::pop() {
	if (elementos.empty()) {
		return nullptr; 
	} else {
		T ret = elementos.front();
		elementos.pop();
		return ret;
	}
}