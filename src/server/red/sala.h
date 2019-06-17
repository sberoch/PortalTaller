#ifndef __SALA_H__
#define __SALA_H__

class Sala {
    private:
    Sala(const Sala& otra) = delete;    
    Sala& operator=(const Sala& otra) = delete;

    public:
    Sala();
    Sala(Sala&& otra);
    Sala& operator=(Sala&& otra);
};

#endif
