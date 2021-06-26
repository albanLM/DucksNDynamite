#ifndef TANGIBLEENTITY_H
#define TANGIBLEENTITY_H

#include "entity.h"
#include "hitbox.h"
#include "GraphicalEngine/graphicalobject.h"

class TangibleEntity : public Entity
{
public:
	TangibleEntity(GraphicalObject graphicalObject);

	Hitbox hitbox() const;

protected:
	Hitbox _hitbox;
};

#endif // TANGIBLEENTITY_H
