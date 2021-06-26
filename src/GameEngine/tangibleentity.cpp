#include "tangibleentity.h"

TangibleEntity::TangibleEntity(GraphicalObject graphicalObject):Entity(graphicalObject)
{

}

Hitbox TangibleEntity::hitbox() const
{
    return _hitbox;
}
