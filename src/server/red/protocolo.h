#ifndef __PROTOCOLO_H__
#define __PROTOCOLO_H__

#include <string>

#include "socket.h"

#define LEN_8 1
#define LEN_16 2
#define LEN_32 4

// Permite enviar y recibir distintos tipos de datos a través de un socket.
// Los datos numéricos se envían y reciben en formato sin signo de 8, 16,
// y 32 bits. Las cadenas de caracteres se envían y reciben por medio
// de los strings de la librería estándar.
class Protocolo {
    private:
    Protocolo(const Protocolo& otro) = delete;

    Protocolo& operator=(const Protocolo& otro) = delete;
    
    public:
    Protocolo();

    Protocolo(Protocolo&& otro);

    Protocolo& operator=(Protocolo&& otro);

    ~Protocolo();

    void enviar(uint8_t unNumero, Socket& s);

    uint8_t recibirNum8Bits(Socket& s);

    void enviar(uint16_t unNumero, Socket& s);

    uint16_t recibirNum16Bits(Socket& s);

    void enviar(uint32_t unNumero, Socket& s);

    uint32_t recibirNum32Bits(Socket& s);

    void enviar(int unNumero, Socket& s);

    int recibirInt(Socket& s);

    void enviar(const std::string& unString, Socket& s);

    std::string recibirString(Socket& s);
};

#endif
