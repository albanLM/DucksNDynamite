#ifndef CONTROLLERSMANAGER_H
#define CONTROLLERSMANAGER_H

#include <SDL2/SDL.h>

#include "window_controller.h"
#include "keyboard_controller.h"
#include "actions.h"

class ControllersManager
{
public:
	ControllersManager();

	void processEvents(Actions * pActions);

private:
	WindowController _windowController;
	KeyboardController _keyboardController;
};

#endif // CONTROLLERSMANAGER_H
