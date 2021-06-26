#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include "controller.h"

class KeyboardController : public Controller
{
public:
	KeyboardController();
	void processEvent(SDL_Event event, Actions * pActions);
};

#endif // KEYBOARDCONTROLLER_H
