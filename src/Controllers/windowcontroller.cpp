#include "windowcontroller.h"

WindowController::WindowController()
{

}

void WindowController::processEvent(SDL_Event event, Actions * pActions)
{
	switch (event.window.event) {
		case SDL_WINDOWEVENT_CLOSE:
			pActions->setQuitGame(true);
			break;
		default:
			break;
	}
}
