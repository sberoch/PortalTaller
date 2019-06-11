#ifndef ESCENA_BASE_H
#define ESCENA_BASE_H

class EscenaBase {
public:
	virtual bool termino() = 0;
	virtual void actualizar() = 0;
	virtual void dibujar() = 0;
	virtual int manejarEventos() = 0;
	virtual ~EscenaBase() {}
};

#endif // ESCENA_BASE_H
