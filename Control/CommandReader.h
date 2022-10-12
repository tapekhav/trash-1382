#ifndef LABS_COMMANDERREADER_H
#define LABS_COMMANDERREADER_H

#include <iostream>
#include "../Characters/Player.h"

class CommandReader {
public:
    void read_step();
    void read_size();
    void read_char();

    int get_height() const;
    int get_width() const;
    char get_char() const;
    Player::STEP get_step() const;

    void print_win() const;
    void print_death() const;
private:
    void check(int& arg);

    char choice;
    int height;
    int width;
    Player::STEP step;
};

#endif