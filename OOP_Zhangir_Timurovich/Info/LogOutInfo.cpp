//
// Created by roman on 25.10.2022.
//

#include "LogOutInfo.h"

std::vector <LEVEL> LogOutInfo::get_levels(){
    return this->levels;
}

std::vector <OUTPUT> LogOutInfo::get_outputs(){
    return this->outputs;
}

LogOutInfo::LogOutInfo(std::vector<OUTPUT> outputs, std::vector<LEVEL> levels){
    this->outputs = outputs;
    this->levels = levels;
}
