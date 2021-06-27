#include "entity.h"

Entity::Entity(GraphicalObject graphicalObject):_graphicalObject(graphicalObject)
{
}

GraphicalObject *Entity::graphicalObject()
{
	return &_graphicalObject;
}
