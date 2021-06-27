#include "game.h"
#include "actions.h"
#include <iostream>

using namespace std;

std::unique_ptr<Game> Game::_instance;

Game::Game(int width, int height)
{
	Window * pWindow = Window::Instance();
	pWindow->resize(width,height);
}

Game::~Game() {
    while (!_spriteSheets.empty()) {
        auto it = _spriteSheets.begin();
        delete it->second;
        _spriteSheets.erase( it );
    }
}

unique_ptr<Game> & Game::Instance()
{
	if (_instance == nullptr)
	{
        // If no instance of game exists, create a new instance
		_instance = std::unique_ptr<Game>(new Game());
	}
	// Else
	return _instance;
}

void Game::run()
{
    // Add plans to the scene
	_scene.addPlan(2.0);
    _scene.addPlan(1.0);

    // Load and add the sprite sheets to the scene
	const char * file = "../sprites/MegamanX_Zero_spritesheet_green.png";
	SpriteSheet *pSpriteSheet = loadSpriteSheet(file);
	Rectangle rec(8,14,38,44);
	GraphicalObject g1(pSpriteSheet, rec, 3, 0, 0);
	GraphicalObject g2(pSpriteSheet, rec, 3, 200, 0);
	Hitbox hitbox(8,14,38,44);

	Character *pCharacter = new Character(g1,hitbox);
	Entity *pEntity = new Entity(g2);
	_scene.addObjectToPlan(pCharacter->graphicalObject(), 0);
	_scene.addObjectToPlan(pEntity->graphicalObject(), 1);

	// Game loop. Runs until the user presses ESCAPE.
	while(!_actions[Actions::Quit])
	{
		_scene.displayGame();
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
                    pCharacter->move(Up);
                    break;
                case Actions::Down:
                    pCharacter->move(Down);
                    break;
                case Actions::Left:
                    pCharacter->move(Left);
                    break;
                case Actions::Right:
                    pCharacter->move(Right);
                    break;
                case Actions::Enter:
                    delete pEntity;
                    pEntity = nullptr;
            }
        }
	}
}

SpriteSheet* Game::loadSpriteSheet(std::string const &fileName)
{
    // Search in memory the sprite sheet with given name
	auto i = _spriteSheets.find(fileName);

	// If the given sprite sheet was not found in memory, load the fileName
	if(i == _spriteSheets.end())
	{
		// Load the sprite sheet
		SpriteSheet *pSpriteSheet = new SpriteSheet(Window::Instance()->pRenderer(), fileName);
		// Insert the sprite sheet into the map
		_spriteSheets.insert(i, pair<std::string, SpriteSheet*>(fileName, pSpriteSheet));
		return pSpriteSheet;
	}

	// Else, return the one that was found
	return i->second;
}
