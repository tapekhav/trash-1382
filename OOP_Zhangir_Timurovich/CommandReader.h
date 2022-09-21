#pragma once

#include <string>
#include <iostream>


class CommandReader {
public:
    explicit CommandReader(int health = 100, int armour = 100, int damage = 100);

    ~CommandReader() = default;

    void set_size();

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


private:
    int width{};
    int height{};
    int health;
    int armour;
    int damage;
    MOVES move;
};
