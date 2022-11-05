#ifndef LABS_GETCONTROL_H
#define LABS_GETCONTROL_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "IConfig.h"

class FileConfig : public IConfig {
public:
    explicit FileConfig(const std::string&);
    std::map<char, Player::STEP> get_config() override;
    ~FileConfig() override;
private:
    std::ifstream file;
};


#endif
