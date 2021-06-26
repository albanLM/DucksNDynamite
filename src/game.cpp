#include "game.h"

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
	_pScene->addPlan(1.0);
	const char * file = "/home/william/Documents/Projet JV/Sprites/MegamanX_Zero_spritesheet_green.png";
	Spritesheet * spritesheet = loadSpritesheet(file);
	Rectangle rec(8,14,38,44);
	GraphicalObject g1(spritesheet,rec,5,0,0);
	GraphicalObject g2(spritesheet,rec,5,200,0);

	Entity * e1 = new Entity(g1);
	Entity * e2 = new Entity(g2);
	_pScene->addObjectToPlan(e1->pGraphicalObject(), 0);
	_pScene->addObjectToPlan(e2->pGraphicalObject(), 0);
	while(!_actions.quitGame())
	{
		_pScene->displayGame();
		_controllersManager.processEvents(&_actions);
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
