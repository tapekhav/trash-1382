#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "../Info/Structs.h"
#include "../Info/LogOutInfo.h"


class CommandReader {
public:

    explicit CommandReader(int health = 100, int armour = 100, int damage = 100);

    ~CommandReader() = default;

    void set_size();

    void set_output();

    void set_level();

    [[nodiscard]] int get_width() const;

    [[nodiscard]] int get_height() const;

    enum MOVES {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        NOWHERE
    };

    bool set_move();

    MOVES get_move();

    std::vector <LEVEL> get_levels();

    std::vector <OUTPUT> get_outputs();


private:
    int width{};
    int height{};
    int health;
    int armour;
    int damage;
    MOVES move;
    std::vector <OUTPUT> outputs;
    std::vector <LEVEL> levels;
};
