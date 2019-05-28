#ifndef SOCKET
#define SOCKET

#include <stddef.h>
#include <sys/types.h>
#include <string.h>
#include <string>
#include <cstdint>

#define SKT_OK 0
#define SKT_INVALIDO -1
#define SKT_FALLO_CONEXION -2
#define SKT_ERROR -3

class Socket {
private:
    int fd;
    explicit Socket(int nuevoFd);

public:
    //Construye el socket
    Socket();
    Socket(Socket&& origen);
	Socket& operator=(Socket&& origen); 

    // Bindea un socket al puerto especificado, y lo pone a la
    // espera de conectar con clientes. 
    // Se escucha a un maximo de 'maxClientes' a la vez.
    int vincularYEscuchar(const char* puerto, size_t maxClientes);

    //Conecta un socket cliente con un servidor.
    int conectar(const char* hostname, const char* puerto);

    // En caso de haber algun cliente tratando de conectarse, el servidor trata
    // de aceptar la conexion. De concretarse, devuelve un nuevo Socket
    // resultado de esa conexion
    Socket aceptar();

    //Envia un mensaje de un cierto largo especificado.
    int enviar(const void* buffer, size_t largo);

    //Recibe un mensaje de un cierto largo especificado.
    int recibir(void* buffer, size_t largo);

    //Apaga el socket, de forma que no se puedan recibir ni enviar mensajes.
    void shutdown();

    //Sobrecarga de operadores para recibir o enviar enteros.
	void operator<<(uint32_t num);
	void operator>>(uint32_t& num);

	//Destruye el socket
    ~Socket(); 
};

#endif
