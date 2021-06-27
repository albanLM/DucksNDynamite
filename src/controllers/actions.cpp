#include "actions.h"

bool& Actions::operator[](Actions::Action const &action) {
    return actions.at(action);
}

bool Actions::operator[](Actions::Action const &action) const {
    return actions.at(action);
}
