#include <string>
#include <vector>

#include "protocolo.h"

Protocolo::Protocolo() {
}

Protocolo::Protocolo(Protocolo&& otro) {   
}

Protocolo& Protocolo::operator=(Protocolo&& otro) {
    return *this;
}

Protocolo::~Protocolo() {
}

void Protocolo::enviar(uint8_t unNumero, Socket& s) {
    s.enviar((const char*) &unNumero, LEN_8);
}

uint8_t Protocolo::recibirNum8Bits(Socket& s) {
    uint8_t resultadoRed = 0;
    s.recibir((char*) &resultadoRed, LEN_8);
    return resultadoRed;
}

void Protocolo::enviar(uint16_t unNumero, Socket& s) {
    uint16_t numeroRed = htons(unNumero);
    s.enviar((const char*) &numeroRed, LEN_16);
}

uint16_t Protocolo::recibirNum16Bits(Socket& s) {
    uint16_t resultadoRed = 0;
    s.recibir((char*) &resultadoRed, LEN_16);
    return ntohs(resultadoRed);
}

void Protocolo::enviar(uint32_t unNumero, Socket& s) {
    uint32_t numeroRed = htonl(unNumero);
    s.enviar((const char*) &numeroRed, LEN_32);
}

uint32_t Protocolo::recibirNum32Bits(Socket& s) {
    uint32_t resultadoRed = 0;
    s.recibir((char*) &resultadoRed, LEN_32);
    return ntohl(resultadoRed);
}

void Protocolo::enviar(int unNumero, Socket& s) {
    uint32_t numeroRed = htonl(unNumero);
    int send = unNumero;
    s.enviar((const char*) &send, LEN_32);
}

int Protocolo::recibirInt(Socket& s) {
    int resultadoRed = 0;
    s.recibir((char*) &resultadoRed, LEN_32);
    return (int)ntohl(resultadoRed);
}

void Protocolo::enviar(const std::string& unString, Socket& s) {
    uint32_t tamanio = unString.size();
    enviar(tamanio, s);
    s.enviar(unString.c_str(), tamanio);
}

std::string Protocolo::recibirString(Socket& s) {
    uint32_t tamanio = recibirNum32Bits(s);
    std::vector<char> stringRed(tamanio);
    s.recibir(stringRed.data(), tamanio);
    std::string recibida(stringRed.data(), tamanio);
    return std::move(recibida);
}
