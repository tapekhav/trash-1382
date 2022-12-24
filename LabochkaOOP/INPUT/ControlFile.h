//
// Created by corvussharp on 07.11.22.
//

#ifndef LABOCHKAOOP_CONTROLFILE_H
#define LABOCHKAOOP_CONTROLFILE_H

#include "ControlConfig.h"

class ControlFile : public ControlConfig {
public:

    explicit ControlFile(const std::string &);
    void read_config() override;
    CONTROL get_key(char key);
    void check_fix_config() override;
    ~ControlFile();
private:
    std::ifstream config;
    std::map<CONTROL, char> empty_config = {
            {CONTROL::UP,    '\0'},
            {CONTROL::DOWN,  '\0'},
            {CONTROL::LEFT,  '\0'},
            {CONTROL::RIGHT, '\0'},
            {CONTROL::EXIT,  '\0'}
    };
    std::map<CONTROL, char> default_config = {
            {CONTROL::UP,    'w'},
            {CONTROL::DOWN,  's'},
            {CONTROL::LEFT,  'a'},
            {CONTROL::RIGHT, 'd'},
            {CONTROL::EXIT,  'e'}

    };
    std::map<std::string, CONTROL> commands = {
            {"UP=", UP},
            {"DOWN=", DOWN},
            {"RIGHT=",RIGHT},
            {"LEFT=", LEFT},
            {"EXIT=", EXIT}
    };

};

#endif //LABOCHKAOOP_CONTROLFILE_H
