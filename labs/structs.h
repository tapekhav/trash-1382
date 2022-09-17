#ifndef LABS_STRUCTS_H
#define LABS_STRUCTS_H

#include <algorithm>

enum STEP {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum OBJECT {
    STANDARD,
    ENEMY,
    BOX,
    HEAL,
    BARRIER,
    PLAYER
};

struct Coordinates {
    int x, y;
} typedef Coordinates;

#endif //LABS_STRUCTS_H
