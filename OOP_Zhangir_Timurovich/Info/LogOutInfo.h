#pragma once

#include "Structs.h"
#include <vector>
#include <string>
//#include "../Output/ConsoleOut.h"
//#include "../Output/FileOut.h"

class LogOutInfo {
public:
    LogOutInfo(std::vector <OUTPUT> outputs, std::vector <LEVEL> levels);

    std::vector <LEVEL> get_levels();

    std::vector <OUTPUT> get_outputs();

    std::vector <LEVEL> set_levels(std::vector<LEVEL> levels);

    std::vector <OUTPUT> set_outputs(std::vector<OUTPUT> outputs);


private:
    std::vector <OUTPUT> outputs;
    std::vector <LEVEL> levels;
};


//#endif //MAIN_CPP_LOGOUTINFO_H
