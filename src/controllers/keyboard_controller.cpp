#include <iostream>
#include "keyboard_controller.h"

// TODO: Refactor this. Add a file with a key-to-action map.

void KeyboardController::processEvent(SDL_Event event, Actions * pActions)
{
    switch(event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
                case SDLK_KP_SPACE:
                    (*pActions)[Actions::Confirm] = true;
                    break;
                case SDLK_z:
                    (*pActions)[Actions::Up] = true;
                    break;
                case SDLK_s:
                    (*pActions)[Actions::Down] = true;
                    break;
                case SDLK_q:
                    (*pActions)[Actions::Left] = true;
                    break;
                case SDLK_d:
                    (*pActions)[Actions::Right] = true;
                    break;
                case SDLK_RETURN:
                    (*pActions)[Actions::Enter] = true;
                    break;
                default:
                    break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.sym) {
                case SDLK_ESCAPE:
                    (*pActions)[Actions::Quit] = true;
                    break;
                case SDLK_KP_SPACE:
                    (*pActions)[Actions::Confirm] = false;
                    break;
                case SDLK_z:
                    (*pActions)[Actions::Up] = false;
                    break;
                case SDLK_s:
                    (*pActions)[Actions::Down] = false;
                    break;
                case SDLK_q:
                    (*pActions)[Actions::Left] = false;
                    break;
                case SDLK_d:
                    (*pActions)[Actions::Right] = false;
                    break;
                case SDLK_RETURN:
                    (*pActions)[Actions::Enter] = false;
                    break;
                default:
                    break;
            }
            break;
	}
}
