#ifndef HITBOX_H
#define HITBOX_H

#include "rectangle.h"

class Hitbox : public Rectangle
{
public:
	Hitbox(float x, float y, float width, float height);
	Hitbox();

	bool isCrossing(Hitbox * h);
};

#endif // HITBOX_H
