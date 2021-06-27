#include <iostream>

#include "window.h"
#include "game.h"

int main()
{
	Window * pWindow = Window::Instance();
	std::unique_ptr<Game> &pGame = Game::Instance();

	pGame->run();

	free(pWindow);
	return 0;
}
