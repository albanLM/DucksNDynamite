#include "spritesheet.h"

SpriteSheet::SpriteSheet(SDL_Renderer* pRenderer,
                         std::string const &file,
                         Uint8 backgroundRed,
                         Uint8 backgroundGreen,
                         Uint8 backgroundBlue):_file(file)
{
	_pImage = IMG_Load(file.c_str());
	_backgroundColor = SDL_MapRGB(_pImage->format,backgroundRed,backgroundGreen,backgroundBlue);
	SDL_SetColorKey(_pImage, SDL_TRUE,_backgroundColor);
	_pTexture = SDL_CreateTextureFromSurface(pRenderer,_pImage);
}

SpriteSheet::SpriteSheet(SDL_Renderer* pRenderer, std::string const &file):
        SpriteSheet(pRenderer, file, 0, 255, 0)
{
}

SpriteSheet::~SpriteSheet()
{
	SDL_DestroyTexture(_pTexture);
	SDL_FreeSurface(_pImage);
}

SDL_Texture *SpriteSheet::pTexture() const
{
	return _pTexture;
}
