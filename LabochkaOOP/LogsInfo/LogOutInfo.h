//
// Created by corvussharp on 26.10.22.
//

#ifndef LABOCHKAOOP_LOGOUTINFO_H
#define LABOCHKAOOP_LOGOUTINFO_H

#include "Structs.h"
#include <vector>
#include <string>
#include "../OutPut/ConsoleOutput.h"
#include "../OutPut/FileOutput.h"

class LogOutInfo {
public:
    LogOutInfo(std::vector <OUTPUT> outputs, std::vector <LEVEL> levels);

    std::vector <LEVEL> get_levels();

    std::vector <OUTPUT> get_outputs();


private:
    std::vector <OUTPUT> outputs;
    std::vector <LEVEL> levels;
    FileOutput *file;
    ConsoleOutput *console;
};


#endif //LABOCHKAOOP_LOGOUTINFO_H
