#ifndef EVENT_HANDLER
#define EVENT_HANDLER 

#include <SDL2/SDL.h>

class EventHandler {
private:
	SDL_Event event;
	bool termino;
public:
	bool quit() const;
	void poll();
	
};

#endif