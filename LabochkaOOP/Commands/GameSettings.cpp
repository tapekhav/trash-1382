//
// Created by corvussharp on 22.11.22.
//

#include "GameSettings.h"

std::vector<LEVEL> GameSettings::get_levels() {
    return this->levels;
}

int GameSettings::get_height() const {
    return this->height;
}

int GameSettings::get_width() const {
    return this->width;
}

std::vector<OUTPUT> GameSettings::get_outputs() {
    return this->outputs;
}
