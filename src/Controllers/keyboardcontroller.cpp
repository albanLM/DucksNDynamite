#include "keyboardcontroller.h"

KeyboardController::KeyboardController()
{

}

void KeyboardController::processEvent(SDL_Event event, Actions * pActions)
{
	switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			pActions->setQuitGame(true);
			break;
		default:
			break;
	}
}
