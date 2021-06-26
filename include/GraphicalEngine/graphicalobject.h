#ifndef GRAPHICALOBJECT_H
#define GRAPHICALOBJECT_H

#include "spritesheet.h"
#include "rectangle.h"
#include "window.h"

class GraphicalObject
{
public:
	GraphicalObject(Spritesheet* spritesheet, Rectangle spriteRect, float sizeCoef, float x, float y, SDL_RendererFlip flip);
	GraphicalObject(Spritesheet* spritesheet, Rectangle spriteRect, float sizeCoef, float x, float y);

	Rectangle spriteRect() const;
	Spritesheet *pSpritesheet() const;
	float sizeCoef() const;
	float x() const;
	float y() const;
	SDL_RendererFlip flip() const;

	void setSpriteRect(const Rectangle &spriteRect);
	void setSizeCoef(float sizeCoef);
	void setCoordinates(float x, float y);
	void setFlip(const SDL_RendererFlip &flip);

private:
	Spritesheet * _pSpritesheet;
	Rectangle _spriteRect;
	float _sizeCoef;
	float _x;
	float _y;
	SDL_RendererFlip _flip;
};

#endif // GRAPHICALOBJECT_H
