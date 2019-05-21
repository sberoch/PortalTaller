#include "Thread.h"

Thread::Thread() {}
Thread::~Thread() {}

Thread::Thread(Thread&& origen) {
    this->thread = std::move(origen.thread);
}
Thread& Thread::operator=(Thread&& origen) {
    this->thread = std::move(origen.thread);
    return *this;
}

void Thread::iniciar() {
	this->thread = std::thread(&Thread::ejecutar, this);
}

void Thread::cerrar() {
	this->thread.join();
}
