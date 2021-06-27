#include "game.h"
#include "actions.h"
#include <iostream>

using namespace std;

Game *Game::_instance = nullptr;

Game::Game()
{
	Window * pWindow = Window::Instance();
	pWindow->resize(640,480);
}

Game::~Game()
{
	free(_pScene);
}
Game* Game::Instance()
{
	if (_instance == nullptr)
	{
		_instance = new Game;
	}
	return _instance;
}

void Game::run()
{
	_pScene = new GraphicalScene();
	_pScene->addPlan(2.0);
    _pScene->addPlan(1.0);
	const char * file = "../sprites/MegamanX_Zero_spritesheet_green.png";
	Spritesheet * spritesheet = loadSpritesheet(file);
	Rectangle rec(8,14,38,44);
	GraphicalObject g1(spritesheet,rec,3,0,0);
	GraphicalObject g2(spritesheet,rec,3,200,0);

	Hitbox hitbox(8,14,38,44);

	Character * character = new Character(g1,hitbox);
	Entity * entity = new Entity(g2);
	_pScene->addObjectToPlan(character->pGraphicalObject(), 0);
	_pScene->addObjectToPlan(entity->pGraphicalObject(), 1);
	while(!_actions[Actions::Quit])
	{
//	    std::cout << "_actions[Actions::Quit] = " << to_string(_actions[Actions::Quit]) << std::endl;
		_pScene->displayGame();
		_controllersManager.processEvents(&_actions);
		// Iterate over possible actions
        for (pair<const Actions::Action, bool> action : _actions.actions) {
            // If action is no activated, skip
            if (!action.second) continue;
            // Else, perform the corresponding action
            switch (action.first) {
                case Actions::Confirm:
                    break;
                case Actions::Up:
                    character->move(Up);
                    break;
                case Actions::Down:
                    character->move(Down);
                    break;
                case Actions::Left:
                    character->move(Left);
                    break;
                case Actions::Right:
                    character->move(Right);
                    break;
            }
        }
	}
}

Spritesheet *Game::loadSpritesheet(const char *file)
{
	map<const char *,Spritesheet *>::iterator i = _spritesheets.find(file);
	if(i == _spritesheets.end())
	{
		//If the file is not loaded yet, load it in the map
		Window *pWindow = Window::Instance();
		Spritesheet * pSpritesheet = new Spritesheet(pWindow->pRenderer(), file);
		_spritesheets.insert(i, pair<const char *,Spritesheet *>(file,pSpritesheet));
		return pSpritesheet;
	}
	return i->second;
}
