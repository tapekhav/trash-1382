#ifndef LABS_COMMANDREADER_H
#define LABS_COMMANDREADER_H

#include <iostream>
#include "../Characters/Player.h"
#include "../Logging/Logger/FileLog.h"
#include "../Logging/LogLevel/Subject.h"

class CommandReader : public Subject {
public:
    void read_step();
    void read_size();
    void read_char();
    char read_choice();
    std::vector<Logger*> read_loggers();

    int get_height() const;
    int get_width() const;
    char get_char() const;
    Player::STEP get_step() const;
private:
    void check(int&);
    std::string read_file_name() const;

    char choice;
    int height;
    int width;
    Player::STEP step;
};

#endif