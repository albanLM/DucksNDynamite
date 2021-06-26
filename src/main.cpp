#include <iostream>

#include "window.h"
#include "game.h"

int main()
{
	Window * pWindow = Window::Instance();
	Game * pGame = Game::Instance();

	pGame->run();

	free(pWindow);
	free(pGame);
	return 0;
}
