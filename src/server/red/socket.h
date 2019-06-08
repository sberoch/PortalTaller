#ifndef __SOCKET_H__
#define __SOCKET_H__

#include <string>
#include <vector>
#include <netdb.h>

#define IP_VERSION AF_INET
#define SOCKET_TYPE SOCK_STREAM
#define FLAGS AI_PASSIVE

#define ERROR_CONEXION "Error al intentar conectar el socket."
#define ERROR_GET_ADDRINFO "Error al llamar a getaddrinfo."
#define ERROR_SET_SOCK_OPT "Error al llamar a setsockopt antes de enlazar."
#define ERROR_BIND "Error al intentar enlazar el socket."
#define ERROR_LISTEN "Error al llamar a listen()."
#define ERROR_ACEPTAR "Error al llamar a accept()."
#define ERROR_CREAR "Error al crear el socket."
#define ERROR_CERRADO_S "Error al enviar. El socket está cerrado."
#define ERROR_CERRADO_R "Error al recibir. El socket está cerrado."
#define ERROR_SEND "Error al enviar. send() devolvió un valor menor a cero."
#define ERROR_RECV "Error al recibir. recv() devolvió un valor menor a cero."


// Socket que permite conectarse a un host y un puerto, si se utiliza como
// cliente, o enlazarse y aceptar conexiones si se utiliza como servidor.
// Permite enviar y recibir datos en formato de bytes.
class Socket {
    private:
    addrinfo* hints_;
    int fd_;

    explicit Socket(int unFd);

    Socket(const Socket& otro) = delete;   
    
    Socket& operator=(const Socket& otro) = delete;

    public:
    Socket();

    // Crea un socket para el host y puerto especificado, dejándolo listo para
    // realizar una conexión o un enlace.
    Socket(const std::string& unHost, const std::string& unPuerto);
    
    ~Socket();

    Socket(Socket&& otro);

    Socket& operator=(Socket&& otro);
    
    // Realiza una conexión para el host y puerto especificados en la creación
    // del socket.
    void conectar();

    // Enlaza el socket al puerto que fue especificado en su creación.
    void enlazar();

    // Pone el socket a la espera de conexiones entrantes.
    // La cantidad máxima de clientes en espera se indica
    // en el parámetro max_en_espera.
    void escuchar(int maxEnEspera);

    // Acepta la conexión de un socket y lo devuelve.
    Socket aceptar();

    // Envía n_bytes de buffer al socket cliente o servidor, según se haya 
    // realizado una aceptaciṕón o una conexión para socket. 
    void enviar(const char* buffer, size_t bytes);

    // Recibe n_bytes en buffer desde socket cliente o servidor, según se haya 
    // realizado una aceptaciṕón o una conexión para socket.
    void recibir(char* buffer, size_t bytes);

    void cerrar();
};

#endif
