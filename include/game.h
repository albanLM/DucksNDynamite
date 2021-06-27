#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <map>
#include <SDL2/SDL.h>

#include "graphical_scene.h"
#include "window.h"
#include "controllers_manager.h"
#include "actions.h"
#include "entity.h"
#include "character.h"

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
