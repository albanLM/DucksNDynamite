#include "tangible_entities/character.h"
#include <cmath>

Character::Character(GraphicalObject const &graphicalObject,Hitbox const &hitbox) : TangibleEntity(graphicalObject,hitbox) {}

void Character::dropBomb() {

}

void Character::move(Direction direction) {
    // Add movement based on player inputs
    float x = 0.0f, y = 0.0f;
    switch (direction) {
        case Up:
            y--;
            break;
        case Down:
            y++;
            break;
        case Left:
            x--;
            break;
        case Right:
            x++;
            break;
    }

    // Normalize the vector
    float dist = sqrt(x*x + y*y);
    x = x / (dist == 0 ? 1 : dist) * _speed;
    y = y / (dist == 0 ? 1 : dist) * _speed;

    // Send the translation to the object
    _graphicalObject.translate(x, y);
}

