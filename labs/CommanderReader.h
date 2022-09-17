#ifndef LABS_COMMANDERREADER_H
#define LABS_COMMANDERREADER_H

#include <iostream>

class CommanderReader {
public:
    explicit CommanderReader();
    ~CommanderReader() = default;
    int get_height() const;
    int get_width() const;
private:
    int height, width;
};

#endif
