#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <iostream>
#include <memory>
#include <map>

#include "graphical_scene.h"
#include "window.h"
#include "controllers_manager.h"
#include "actions.h"
#include "entity.h"
#include "character.h"

/**
 * Main class of the program. Launch the main game loop and quit when the user presses ESCAPE.
 */
class Game
{
    private:
        explicit Game(int width = 640, int height = 480);

        /**
         * @brief Search in memory for a sprite sheet with the given name. If it doesn't exist, load the sprite sheet from the filesystem.
         * @param fileName Name of the fileName containing the sprite sheet
         * @return a pointer to the given sprite sheet stored in memory
         */
        SpriteSheet* loadSpriteSheet(std::string const &fileName);

        Actions _actions;
        GraphicalScene _scene;
        ControllersManager _controllersManager;
        static std::unique_ptr<Game> _instance;
        std::map<std::string, SpriteSheet*> _spriteSheets;

    public:
        ~Game();

        /**
         * @return a singleton instance of Game
         */
        static std::unique_ptr<Game> & Instance();

        /**
         * Run the main game loop, a while loop.
         * Quit when the user presses ESCAPE.
         */
        void run();
};

#endif // GAME_H
