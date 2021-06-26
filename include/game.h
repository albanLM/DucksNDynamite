#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <map>
#include <SDL2/SDL.h>

#include "GraphicalEngine/graphicalscene.h"
#include "GraphicalEngine/window.h"
#include "Controllers/controllersmanager.h"
#include "Controllers/actions.h"
#include "GameEngine/entity.h"

class Game
{
public:
	~Game();
	static Game* Instance();
	void run();

private:
	Game();
	Spritesheet* loadSpritesheet(const char* file);

	static Game * _instance;
	GraphicalScene * _pScene;
	std::map<const char *,Spritesheet *> _spritesheets;
	Actions _actions;
	ControllersManager _controllersManager;
};

#endif // GAME_H
