#ifndef SURVIVE_ENUMS_H
#define SURVIVE_ENUMS_H

class EnumClass {
public:
    enum FIELD_SIZE {
        MIN_SIZE = 3,
        STANDARD_SIZE = 15,
        MAX_SIZE = 20
    };

    enum Commands {
        UNKNOWN,
        RIGHT,
        UP,
        LEFT,
        DOWN,
        QUIT,
        YES,
        NO,
        COUNT_CMD = 8
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
        FINISH,
        DEFEAT,
        VICTORY,
        MOVE_COUNT = 50
    };


    enum Properties {
        THIRST = 20,
        HUNGER = 10,
        HEALTH = 5,
        DAMAGE = 1
    };

    enum Events_Properties {
        BERRY_BUSH = 1,
        WOLF_BUSH = 1,
        BEAR_BUSH = 5,
        RABBIT_BUSH = 5,
        WATER_CAVE = 3,
        SAINT_WATER_CAVE = 5,
        PROBABILITY = 100,
        BOUND = 2,
        LIFE_TIME = 10
    };

    enum Events {
        NONE,
        BERRY,
        WOLF,
        RABBIT,
        BEAR,
        WATER,
        SAINT_WATER,
        TELEPORT,
        EARTHQUAKE
    };

    enum Log {
        LOG_STATUS,
        LOG_ERROR,
        LOG_GAME,
        LOG_UNKNOWN
    };

};

#endif //SURVIVE_ENUMS_H