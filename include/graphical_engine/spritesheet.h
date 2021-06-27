#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

/**
 * Represent a sprite sheet object.
 * Sprite sheets are loaded from the filesystem.
 */
class SpriteSheet
{
public:
    SpriteSheet(SpriteSheet const &spriteSheet);
	SpriteSheet(SDL_Renderer *pRenderer, std::string const &file,
                Uint8 backgroundRed,
                Uint8 backgroundGreen,
                Uint8 backgroundBlue);
	SpriteSheet(SDL_Renderer *pRenderer, std::string const &file);
	~SpriteSheet();

	SDL_Texture *pTexture() const;

private:
	std::string _file;
	SDL_Surface * _pImage;
	Uint32 _backgroundColor;
	SDL_Texture * _pTexture;
};

#endif // SPRITESHEET_H
