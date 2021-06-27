#include "spritesheet.h"

Spritesheet::Spritesheet(SDL_Renderer* pRenderer,
                         const char *file,
                         Uint8 backgroundRed,
                         Uint8 backgroundGreen,
                         Uint8 backgroundBlue):_file(file)
{
	_pImage = IMG_Load(file);
	_backgroundColor = SDL_MapRGB(_pImage->format,backgroundRed,backgroundGreen,backgroundBlue);
	SDL_SetColorKey(_pImage, SDL_TRUE,_backgroundColor);
	_pTexture = SDL_CreateTextureFromSurface(pRenderer,_pImage);
}

Spritesheet::Spritesheet(SDL_Renderer* pRenderer, const char *file):
    Spritesheet(pRenderer,file,0,255,0)
{
}

Spritesheet::~Spritesheet()
{
	SDL_DestroyTexture(_pTexture);
	SDL_FreeSurface(_pImage);
}

SDL_Texture *Spritesheet::pTexture() const
{
	return _pTexture;
}


