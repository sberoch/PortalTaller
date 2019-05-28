#define _POSIX_C_SOURCE 200112L
#include <errno.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#include <string>
#include <iostream>
#include <stdexcept>
#include "Socket.h"

#define CUATRO_BYTES 4


Socket::Socket() {
	int familia = AF_INET;      /* IPv4 (or AF_INET6 for IPv6)     */
	int tipo = SOCK_STREAM;     /* TCP  (or SOCK_DGRAM for UDP)    */
	int protocolo = 0;          /* Any protocol */
	int s = socket(familia, tipo, protocolo);

	// Si falla al crear el socket
	if (s == SKT_INVALIDO)
		throw std::runtime_error("Fallo la creacion del socket");

	this->fd = s;
}

Socket::~Socket() {
	if (this->fd != SKT_INVALIDO)
		close(this->fd);
}

Socket::Socket(int nuevoFd): fd(nuevoFd) {}

Socket::Socket(Socket&& origen): fd(origen.fd) {
	origen.fd = SKT_INVALIDO;
}

Socket& Socket::operator=(Socket&& origen) {
	this->fd = origen.fd;
	origen.fd = SKT_INVALIDO;
	return *this;
}

int Socket::vincularYEscuchar(const char* puerto, size_t maxClientes) {
	struct addrinfo hints;
	struct addrinfo *results, *ptr;
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;          /* IPv4 (or AF_INET6 for IPv6)     */
	hints.ai_socktype = SOCK_STREAM;    /* TCP  (or SOCK_DGRAM for UDP)    */
	hints.ai_flags = AI_PASSIVE;        /* AI_PASSIVE for server           */

	if (getaddrinfo(NULL, puerto, &hints, &results) != 0)
		return SKT_FALLO_CONEXION;

	ptr = results;
	int bindeado = 0;
	while (ptr != NULL){
		if (bind(this->fd, ptr->ai_addr, ptr->ai_addrlen) >= 0) {
			bindeado = 1;
			break;
		}
		ptr = ptr->ai_next;
	}
	freeaddrinfo(results);

	if (bindeado == 0)
		return SKT_FALLO_CONEXION;

	if (listen(this->fd, maxClientes) == -1){
		::shutdown(this->fd, SHUT_RDWR);
		return SKT_ERROR;
	}

	return SKT_OK;
}


int Socket::conectar(const char* hostname, const char* puerto){
	struct addrinfo hints;
	struct addrinfo *results, *ptr;
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;          /* IPv4 (or AF_INET6 for IPv6)     */
	hints.ai_socktype = SOCK_STREAM;    /* TCP  (or SOCK_DGRAM for UDP)    */
	hints.ai_flags = 0;                 /* None                            */

	if (getaddrinfo(hostname, puerto, &hints, &results) != 0)
		return SKT_FALLO_CONEXION;

	ptr = results;
	int conexion_establecida = 0;
	while (ptr != NULL){
		if (connect(this->fd, ptr->ai_addr, ptr->ai_addrlen) >= 0){
			conexion_establecida = 1;
			break;
		}
		ptr = ptr->ai_next;
	}
	freeaddrinfo(results);

	if (conexion_establecida == 0)
		return SKT_FALLO_CONEXION;

	return SKT_OK;
}


Socket Socket::aceptar(){
	int fd = accept(this->fd, NULL, NULL);
	if (fd == SKT_INVALIDO)
		throw std::runtime_error("Fallo al aceptar una conexion\n");

	Socket peerSocket(fd);
	return std::move(peerSocket);
}


int Socket::enviar(const void* buffer, size_t largo){
	int e = 0;
	size_t enviado = 0;
	const char* buf = (const char*) buffer;

	while (enviado < largo){
		e = send(this->fd, &buf[enviado],
							largo - enviado, MSG_NOSIGNAL);
		if (e == 0){
			return SKT_FALLO_CONEXION;
		}
		if (e < 0){
			return SKT_ERROR;
		}
		enviado += e;
	}
	return enviado;
}


int Socket::recibir(void* buffer, size_t largo){
	int r = 0;
	size_t recibido = 0;
	char* buf = (char*) buffer;
	while (recibido < largo){
		r = recv(this->fd, &buf[recibido],
							largo - recibido, MSG_NOSIGNAL);
		if (r == 0){
			return SKT_FALLO_CONEXION;
		}
		if (r < 0){
			return SKT_ERROR;
		}
		recibido += r;
	}
	return recibido;
}


void Socket::shutdown(){
	::shutdown(this->fd, SHUT_RDWR);
}

void Socket::operator<<(uint32_t num) {
	this->enviar((char*) &num, CUATRO_BYTES);
}

void Socket::operator>>(uint32_t& num) {
	this->recibir((char*) &num, CUATRO_BYTES);
}
