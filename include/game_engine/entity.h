#ifndef ENTITY_H
#define ENTITY_H

#include "graphical_object.h"

class Entity
{
public:
	Entity(GraphicalObject graphicalObject);

	GraphicalObject * graphicalObject();

protected:
	GraphicalObject _graphicalObject;
};

#endif // ENTITY_H
