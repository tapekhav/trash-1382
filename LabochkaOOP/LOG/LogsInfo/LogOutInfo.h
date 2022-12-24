//
// Created by corvussharp on 26.10.22.
//

#ifndef LABOCHKAOOP_LOGOUTINFO_H
#define LABOCHKAOOP_LOGOUTINFO_H

#include "Structs.h"
#include <vector>
#include <string>


class LogOutInfo {
public:
    LogOutInfo(std::vector<OUTPUT> outputs, std::vector<LEVEL> levels);

    std::vector<LEVEL> get_levels() const;

    std::vector<OUTPUT> get_outputs() const;

    std::vector<LEVEL> set_levels(std::vector<LEVEL> levels);

    std::vector<OUTPUT> set_outputs(std::vector<OUTPUT> outputs);


private:
    std::vector<OUTPUT> outputs;
    std::vector<LEVEL> levels;
};

#endif //LABOCHKAOOP_LOGOUTINFO_H
