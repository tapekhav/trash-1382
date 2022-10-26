//
// Created by corvussharp on 26.10.22.
//


#include "LogOutInfo.h"

#include <utility>

std::vector <LEVEL> LogOutInfo::get_levels(){
    return this->levels;
}

std::vector <OUTPUT> LogOutInfo::get_outputs(){
    return this->outputs;
}

LogOutInfo::LogOutInfo(std::vector<OUTPUT> outputs, std::vector<LEVEL> levels){
    this->outputs = std::move(outputs);
    this->levels = std::move(levels);
    this->file = new FileOutput("logs.txt");
    this->console = new ConsoleOutput;
}