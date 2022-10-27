//
// Created by roman on 25.10.2022.
//

#include "LogOutInfo.h"

std::vector <LEVEL> LogOutInfo::get_levels() {
    return this->levels;
}

std::vector <LEVEL> LogOutInfo::set_levels(std::vector <LEVEL> levels) {
    return this->levels;
}

std::vector <OUTPUT> LogOutInfo::get_outputs() {
    return this->outputs;
}

std::vector <OUTPUT> LogOutInfo::set_outputs(std::vector <OUTPUT> outputs) {
    return this->outputs;
}

LogOutInfo::LogOutInfo(std::vector <OUTPUT> outputs, std::vector <LEVEL> levels) {
    this->outputs = outputs;
    this->levels = levels;
}
