#include "actions.h"

Actions::Actions()
{

}

bool Actions::quitGame() const
{
	return _quitGame;
}

void Actions::setQuitGame(bool quitGame)
{
	_quitGame = quitGame;
}
