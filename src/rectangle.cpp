#include "rectangle.h"

Rectangle::Rectangle(float x, float y, float width, float height):
    _x(x), _y(y), _width(width), _height(height)
{
}

Rectangle::Rectangle():Rectangle(0.0, 0.0, 0.0, 0.0)
{
}

SDL_Rect Rectangle::toSdlRect()
{
	return SDL_Rect{(int)_x,
		            (int)_y,
		            (int)_width,
		            (int)_height};
}

float Rectangle::x() const
{
	return _x;
}

float Rectangle::y() const
{
	return _y;
}

float Rectangle::width() const
{
	return _width;
}

float Rectangle::height() const
{
	return _height;
}

void Rectangle::setX(float x)
{
	_x = x;
}

void Rectangle::setY(float y)
{
	_y = y;
}

void Rectangle::setWidth(float width)
{
	_width = width;
}

void Rectangle::setHeight(float height)
{
	_height = height;
}
