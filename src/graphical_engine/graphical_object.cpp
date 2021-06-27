#include "graphical_object.h"

GraphicalObject::GraphicalObject(SpriteSheet *spritesheet, Rectangle spriteRect, float sizeCoef,
                                 float x, float y, SDL_RendererFlip flip):
    _pSpritesheet(spritesheet), _spriteRect(spriteRect), _sizeCoef(sizeCoef), _x(x), _y(y), _flip(flip)
{

}

GraphicalObject::GraphicalObject(SpriteSheet *spritesheet, Rectangle spriteRect, float sizeCoef, float x, float y):
    GraphicalObject(spritesheet, spriteRect, sizeCoef, x, y, SDL_FLIP_NONE)
{
}

Rectangle GraphicalObject::spriteRect() const
{
	return _spriteRect;
}

SpriteSheet *GraphicalObject::pSpritesheet() const
{
	return _pSpritesheet;
}

float GraphicalObject::sizeCoef() const
{
	return _sizeCoef;
}

float GraphicalObject::x() const
{
	return _x;
}

float GraphicalObject::y() const
{
	return _y;
}

SDL_RendererFlip GraphicalObject::flip() const
{
	return _flip;
}

void GraphicalObject::setSpriteRect(const Rectangle &spriteRect)
{
	_spriteRect = spriteRect;
}

void GraphicalObject::setSizeCoef(float sizeCoef)
{
	_sizeCoef = sizeCoef;
}

void GraphicalObject::setCoordinates(float x, float y)
{
	_x = x;
	_y = y;
}

void GraphicalObject::setFlip(const SDL_RendererFlip &flip)
{
	_flip = flip;
}

void GraphicalObject::translate(float x, float y) {
    _x += x;
    _y += y;
}
