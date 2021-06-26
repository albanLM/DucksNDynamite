#include "hitbox.h"

Hitbox::Hitbox(float x, float y, float width, float height):Rectangle(x,y,width,height)
{
}

Hitbox::Hitbox():Rectangle()
{
}

bool Hitbox::isCrossing(Hitbox *h)
{
	//if (x1<=x2 && x1+w1>=x2) || (x2<=x1 && x2+w2>=x1)
	//if (y1<=y2 && y1+h1>=y2) || (y2<=y1 && y2+h2>=y1)
	bool xCrossing = (_x<=h->x() && _x+_width >= h->x()) || (h->x()<=_x && h->x()+h->width() >= _x);
	bool yCrossing = (_y<=h->y() && _y+_height >= h->y()) || (h->y()<=_y && h->y()+h->height() >= _y);
	return (xCrossing && yCrossing);
}
