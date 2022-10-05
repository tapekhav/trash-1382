#ifndef ENUM_H
#define ENUM_H


class Enum {
public:
    enum PlayerStats{
        HEALTH = 100,
        ATTACK_POWER = 5,
        KEY_ABILITY = 0
    };

    enum CellType{
        LAND,
        STONE,
        PIT,
        CHEST,
        KEY,
        ENEMY
    };

    enum FieldDefaultSize{
        DEFAULT_HEIGHT_OF_FIELD = 12,
        DEFAULT_WIDTH_OF_FIELD = 16
    };

    enum Direction{
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
};


#endif
