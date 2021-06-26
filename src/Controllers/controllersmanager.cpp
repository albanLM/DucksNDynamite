#include "controllersmanager.h"

ControllersManager::ControllersManager()
{
}

void ControllersManager::processEvents(Actions *pActions)
{
	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_WINDOWEVENT:
				_windowController.processEvent(event, pActions);
				break;
			case SDL_KEYUP:
				_keyboardController.processEvent(event, pActions);
				break;
		}
	}
}
