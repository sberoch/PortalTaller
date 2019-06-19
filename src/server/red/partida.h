#ifndef __PARTIDA_H__
#define __PARTIDA_H__

class Partida {
    private:
    Partida(const Partida& otra) = delete;    
    Partida& operator=(const Partida& otra) = delete;

    public:
    Partida();
    Partida(Partida&& otra);
    Partida& operator=(Partida&& otra);
    int cantidadDeJugadores() {return 2;}
};

#endif
