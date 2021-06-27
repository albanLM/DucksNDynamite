#include "window_controller.h"

WindowController::WindowController()
{

}

void WindowController::processEvent(SDL_Event event, Actions * pActions)
{
	switch (event.window.event) {
		case SDL_WINDOWEVENT_CLOSE:
			(*pActions)[Actions::Quit] = true;
			break;
		default:
			break;
	}
}
