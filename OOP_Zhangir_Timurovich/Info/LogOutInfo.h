#ifndef MAIN_CPP_LOGOUTINFO_H
#define MAIN_CPP_LOGOUTINFO_H

#include "Structs.h"
#include <vector>
#include <string>
#include "../Output/ConsoleOut.h"
#include "../Output/FileOut.h"

class LogOutInfo {
public:
    LogOutInfo(std::vector <OUTPUT> outputs, std::vector <LEVEL> levels);

    std::vector <LEVEL> get_levels();

    std::vector <OUTPUT> get_outputs();


private:
    std::vector <OUTPUT> outputs;
    std::vector <LEVEL> levels;
    FileOut *file;
    ConsoleOut *console;
};


#endif //MAIN_CPP_LOGOUTINFO_H
