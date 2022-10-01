#ifndef SURVIVE_ENUMS_H
#define SURVIVE_ENUMS_H

class EnumClass {
public:
    enum FIELD_SIZE{
        MIN_SIZE = 2,
        STANDARD_SIZE = 15,
        MAX_SIZE = 20
    };

    enum Direction {
        RIGHT,
        UP,
        LEFT,
        DOWN
    };

    enum FieldObj {
        BORDER_ABOVE_AND_BOTTOM,
        BORDER_LEFT_AND_RIGHT,
        BORDER_RIGHT_ABOVE_AND_LEFT_BOTTOM,
        BORDER_RIGHT_BOTTOM_AND_LEFT_ABOVE,
        PLAYER
    };

    enum Action {
        FIELD_SIZE,
        GAME_PROGRESS,
        DO_CMD,
        FINISH
    };

    enum Properties{  
        THIRST = 20,
        HUNGER = 10,
        HEALTH = 5
    };
};

#endif //SURVIVE_ENUMS_H