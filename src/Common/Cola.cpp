#include "Cola.h"
#include "Evento.h"

template<class T>
void Cola<T>::put(T elem) {
	elementos.push(elem);
}

template<class T>
bool Cola<T>::get(T& elem) {
	if (elementos.empty()) {
		return false; 
	} else {
		elem = elementos.front();
		elementos.pop();
		return true;
	}
}

template class Cola<Evento>;