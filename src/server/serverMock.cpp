#include <iostream>
#include "../Common/Socket.h"
#include "../Common/Serializador.h"
#include "../Common/Evento.h"

int main(int argc, char const *argv[]) {

	Serializador serializador;
	Socket socket;
	std::cout << "Socket creado\n";

	socket.vincularYEscuchar("8888", 50);
	std::cout << "Socket vinculado y escuchando\n";

	Socket peerSocket = socket.aceptar();
	std::cout << "Socket aceptado\n";

	Evento* evento = new EventoCreacionPersonaje(29);
	evento->enviarPorSocket(peerSocket);

	while (true) {
		Evento* evento = serializador.recibirEvento(peerSocket);
		std::cout << "Evento recibido\n";
		evento->enviarPorSocket(peerSocket);
		std::cout << "Evento enviado\n";
	}

	return 0;
} 