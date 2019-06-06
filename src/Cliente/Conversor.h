#ifndef CONVERSOR_H
#define CONVERSOR_H

class Conversor {
private:
	int pixelesPorBloque;
public:
	Conversor(int pixelesPorBloque);
	int bloqueAPixel(int coord);
	int pixelABloque(int coord);
};

#endif // CONVERSOR_H
