#include <iostream>
#include "Socket.h"
#include "Serializador.h"
#include "Evento.h"

int main(int argc, char const *argv[]) {

	Serializador serializador;
	Socket socket;
	std::cout << "Socket creado\n";

	socket.vincularYEscuchar("8888", 50);
	std::cout << "Socket vinculado y escuchando\n";

	Socket socketEnviar = socket.aceptar();
	std::cout << "Socket de envio aceptado\n";

	Socket socketRecibir = socket.aceptar();
	std::cout << "Socket de recepcion aceptado\n";

	Evento* evento = new EventoCreacionPersonaje(29);
	evento->enviarPorSocket(socketEnviar);

	while (true) {
		Evento* evento = serializador.recibirEvento(socketRecibir);
		std::cout << "Evento recibido\n";
		evento->enviarPorSocket(socketEnviar);
		std::cout << "Evento enviado\n";
	}

	return 0;
}