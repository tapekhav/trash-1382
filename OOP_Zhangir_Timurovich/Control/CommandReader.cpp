//
// Created by roman on 07.11.2022.
//

#include "CommandReader.h"

int CommandReader::get_width() const {
    return this->width;
}

int CommandReader::get_height() const {
    return this->height;
}

std::vector <OUTPUT> CommandeReader::get_outputs() {
    return this->outputs;
}

std::vector <LEVEL> CommandReader::get_levels() {
    return this->levels;
}