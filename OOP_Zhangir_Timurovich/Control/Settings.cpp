//
// Created by roman on 08.11.2022.
//

#include "Settings.h"

int Settings::get_width() const {
    return this->width;
}

int Settings::get_height() const {
    return this->height;
}

std::vector <OUTPUT> Settings::get_outputs() {
    return this->outputs;
}

std::vector <LEVEL> Settings::get_levels() {
    return this->levels;
}