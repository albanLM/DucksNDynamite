#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include "controller.h"

class WindowController : public Controller
{
public:
	WindowController();
	void processEvent(SDL_Event event, Actions * pActions);
};

#endif // WINDOWCONTROLLER_H
