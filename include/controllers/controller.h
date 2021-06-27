#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <SDL2/SDL.h>

#include "actions.h"

class Game;

class Controller
{
public:
	Controller();
	virtual void processEvent(SDL_Event event, Actions * pActions) = 0;
};

#endif // CONTROLLER_H
