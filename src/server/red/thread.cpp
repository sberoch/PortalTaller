#include "server_thread.h"

Thread::Thread() {
}

Thread::Thread(Thread&& otroThread) {
    thread_ = std::move(otroThread.thread_);
}

Thread& Thread::operator=(Thread&& otroThread) {
    thread_ = std::move(otroThread.thread_);
    return *this;
}

void Thread::start() {
    thread_ = std::thread(&Thread::run, this);
}

void Thread::join() {
    thread_.join();
}
