#ifndef DUCKSNDYNAMITE_CHARACTER_H
#define DUCKSNDYNAMITE_CHARACTER_H

#include <tangible_entity.h>

enum Direction {
    Up,
    Down,
    Left,
    Right
};

class Character : public TangibleEntity {
    private:
        Direction _direction {Down};
        float _speed {0.01f};
        int _nbMaxBombs {1};
        int _explosionSize {1};

    public:
        explicit Character(GraphicalObject const &graphicalObject,Hitbox const &hitbox);

        void dropBomb();
        void move(Direction direction);
};


#endif //DUCKSNDYNAMITE_CHARACTER_H
