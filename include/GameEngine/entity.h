#ifndef ENTITY_H
#define ENTITY_H

#include "graphicalobject.h"

class Entity
{
public:
	Entity(GraphicalObject graphicalObject);

	GraphicalObject * pGraphicalObject();

protected:
	GraphicalObject _graphicalObject;
};

#endif // ENTITY_H
