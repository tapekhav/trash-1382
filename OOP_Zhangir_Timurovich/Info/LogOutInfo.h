#ifndef MAIN_CPP_LOGOUTINFO_H
#define MAIN_CPP_LOGOUTINFO_H

#include "Structs.h"
#include <vector>


class LogOutInfo {
public:
    LogOutInfo(std::vector<OUTPUT> outputs, std::vector<LEVEL> levels);

    std::vector <LEVEL> get_levels();

    std::vector <OUTPUT> get_outputs();

private:
    std::vector <OUTPUT> outputs;
    std::vector <LEVEL> levels;
};


#endif //MAIN_CPP_LOGOUTINFO_H
