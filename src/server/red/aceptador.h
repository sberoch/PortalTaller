#ifndef __ACEPTADOR_H__
#define __ACEPTADOR_H__

#include "thread.h"
#include "socket.h"
#include "value_protected.h"

class Aceptador : public Thread {
    private:
    Socket& skt_;
    ValueProtected<bool>& seguirCorriendo_;
};

#endif
