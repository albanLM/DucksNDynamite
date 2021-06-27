#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Spritesheet
{
public:
	Spritesheet(SDL_Renderer *pRenderer, const char *file,
	            Uint8 backgroundRed,
	            Uint8 backgroundGreen,
	            Uint8 backgroundBlue);
	Spritesheet(SDL_Renderer *pRenderer, const char *file);
	~Spritesheet();

	SDL_Texture *pTexture() const;

private:
	const char *_file;
	SDL_Surface * _pImage;
	Uint32 _backgroundColor;
	SDL_Texture * _pTexture;
};

#endif // SPRITESHEET_H
