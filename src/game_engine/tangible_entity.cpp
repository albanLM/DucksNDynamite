#include "tangible_entity.h"

TangibleEntity::TangibleEntity(GraphicalObject graphicalObject, Hitbox hitbox):Entity(graphicalObject),_hitbox(hitbox)
{

}

Hitbox TangibleEntity::hitbox() const
{
    return _hitbox;
}
