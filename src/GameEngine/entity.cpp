#include "entity.h"

Entity::Entity(GraphicalObject graphicalObject):_graphicalObject(graphicalObject)
{
}

GraphicalObject *Entity::pGraphicalObject()
{
	return &_graphicalObject;
}
