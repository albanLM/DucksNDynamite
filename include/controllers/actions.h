#ifndef ACTIONS_H
#define ACTIONS_H

#include <map>

class Actions
{
    public:
        enum Action {
            Quit,
            Confirm,
            Up,
            Down,
            Left,
            Right,
            Enter
        };
        std::map<Action, bool> actions {
            {Quit,false},
            {Confirm, false},
            {Up, false},
            {Down, false},
            {Left, false},
            {Right, false},
            {Enter, false}
        };

        Actions() = default;
        ~Actions() = default;

        bool& operator[](Action const &action);
        bool operator[](Action const &action) const;
};

#endif // ACTIONS_H
