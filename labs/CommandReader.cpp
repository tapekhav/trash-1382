#include "CommanderReader.h"

CommanderReader::CommanderReader() {
    std::cin >> height >> width;
}

int CommanderReader::get_height() const {
    return height;
}

int CommanderReader::get_width() const {
    return width;
}