#ifndef LABS_COMMANDERREADER_H
#define LABS_COMMANDERREADER_H

#include <iostream>
#include "Player.h"

class CommanderReader {
public:
    CommanderReader() = default;
    ~CommanderReader() = default;
    void read_height();
    void read_width();
    void read_step();
    int get_height() const;
    int get_width() const;
    Player::STEP get_step() const;
private:
    int height, width;
    Player::STEP step;
};

#endif
