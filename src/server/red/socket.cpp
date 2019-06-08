#define _POSIX_C_SOURCE 200112L

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netdb.h>
#include <stdexcept>
#include <string.h>
#include <string>

#include "socket.h"

Socket::Socket() :
    hints_(NULL),
    fd_(-1) {
}

Socket::Socket(int unFd) :
    hints_(NULL),
    fd_(unFd) {
}

Socket::Socket(const std::string& unHost, const std::string& unPuerto) :
    hints_(NULL),
    fd_(-1) {
    int status = 0;
    addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = IP_VERSION;    
    hints.ai_socktype = SOCKET_TYPE;
    hints.ai_flags = FLAGS;
    status = getaddrinfo(unHost.c_str(), unPuerto.c_str(), &hints, &hints_);
    if (status != 0) { 
        throw std::runtime_error(ERROR_GET_ADDRINFO);
    }
    fd_ = socket(hints_->ai_family, hints_->ai_socktype, hints_->ai_protocol);
    if (fd_ == -1) {
        throw std::runtime_error(ERROR_CREAR);
    }
}

Socket::Socket(Socket&& otro) {
    hints_ = otro.hints_;
    fd_ = otro.fd_;
    otro.hints_ = NULL;
    otro.fd_ = -1;
}

Socket& Socket::operator=(Socket&& otro) {
    if (this == &otro) {
        return *this;
    }
    if (hints_) {
        freeaddrinfo(hints_);
    }
    if (fd_ != -1) {
        close(fd_);
    }
    hints_ = otro.hints_;
    fd_ = otro.fd_;    
    otro.hints_ = NULL;
    otro.fd_ = -1;    
    return *this;
}

Socket::~Socket() {
    if (fd_ != -1) {
        close(fd_);
    }
    if (hints_) {
        freeaddrinfo(hints_);
    }
}

void Socket::conectar() {
    bool conectado = false;
    int estado = -1;
    addrinfo* ptr = hints_;
    while (ptr != NULL && !conectado) {
        estado = connect(fd_, hints_->ai_addr, hints_->ai_addrlen);
        conectado = (estado != -1);
        ptr = ptr->ai_next;
    }
    if (!conectado) {
        throw std::runtime_error(ERROR_CONEXION);
    }
}

void Socket::enlazar() {
    int opt_val = 1;
    int result_set_opt = setsockopt(fd_, SOL_SOCKET,
        SO_REUSEADDR, &opt_val, sizeof(opt_val));
    if (result_set_opt == -1) {
        throw std::runtime_error(ERROR_SET_SOCK_OPT);
    }
    int status = bind(fd_, hints_->ai_addr, hints_->ai_addrlen);
    if (status == -1) {
        throw std::runtime_error(ERROR_BIND);
    }
}

void Socket::escuchar(int maxEnEspera) {
    int estado = listen(fd_, maxEnEspera);
    if (estado == -1) {
        throw std::runtime_error(ERROR_LISTEN);
    }
}

Socket Socket::aceptar() {
    int fdAceptado = accept(fd_, NULL, NULL);
    if (fdAceptado == -1) {
        throw std::runtime_error(ERROR_ACEPTAR);
    }
    return std::move(Socket(fdAceptado));
}

void Socket::enviar(const char* buffer, size_t bytes) {
    size_t enviados = 0;
    int s = 0;
    while (enviados < bytes) {
        s = send(fd_, &buffer[enviados],
            bytes - enviados, MSG_NOSIGNAL);

        if (s < 0) {
            throw std::runtime_error(ERROR_SEND);
        } else if (s == 0) {
            throw std::runtime_error(ERROR_CERRADO_S);
        } else {
            enviados += s;                       
        }
    }
}

void Socket::recibir(char* buffer, size_t bytes) {
    size_t recibidos = 0;
    size_t s = 0;
    while (recibidos < bytes) {
        s = recv(fd_, &buffer[recibidos],
            bytes - recibidos, MSG_NOSIGNAL);
        if (s < 0) {
            throw std::runtime_error(ERROR_RECV);
        } else if (s == 0) {
            throw std::runtime_error(ERROR_CERRADO_R);
        } else {
            recibidos += s;                       
        }
    }
}

void Socket::cerrar() {
    shutdown(fd_, SHUT_RDWR);
}
