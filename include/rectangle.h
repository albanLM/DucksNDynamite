#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <SDL2/SDL.h>

class Rectangle
{
public:
	Rectangle(float x, float y, float width, float height);
	Rectangle();

	SDL_Rect toSdlRect();

	float x() const;
	float y() const;
	float width() const;
	float height() const;

	void setX(float x);
	void setY(float y);
	void setWidth(float width);
	void setHeight(float height);

protected:
	float _x;
	float _y;
	float _width;
	float _height;
};

#endif // RECTANGLE_H
