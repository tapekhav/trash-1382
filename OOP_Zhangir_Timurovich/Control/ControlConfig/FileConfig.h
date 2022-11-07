//
// Created by roman on 06.11.2022.
//

#ifndef MAIN_CPP_FILECONFIG_H
#define MAIN_CPP_FILECONFIG_H

#include "ControlConfig.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class FileConfig : public ControlConfig {
public:
    explicit FileConfig(const std::string &);

    void read_config() override;

//    MOVES get_key_config(char move) override;

    ~FileConfig() override;

private:
    std::ifstream file;
};


#endif //MAIN_CPP_FILECONFIG_H
