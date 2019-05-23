#ifndef EVENTO
#define EVENTO 

class Evento {
private:
	int x,y;
	int tipoEvento;
	int idItem;
public:
	Evento(int x, int y, int tipoEvento, int idItem);
};

#endif