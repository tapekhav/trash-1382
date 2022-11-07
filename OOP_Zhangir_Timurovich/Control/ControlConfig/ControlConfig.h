//
// Created by roman on 06.11.2022.
//

#ifndef MAIN_CPP_CONTROLCONFIG_H
#define MAIN_CPP_CONTROLCONFIG_H

#include <map>
#include "../../Info/Structs.h"
#include <vector>

class ControlConfig {
public:
    virtual ~ControlConfig() = default;

    virtual void read_config() = 0;

    virtual MOVES get_key_config(char move);

protected:
    void check_config();

    std::map<MOVES, char> control = {
            {MOVES::UP,    '\0'},
            {MOVES::DOWN,  '\0'},
            {MOVES::LEFT,  '\0'},
            {MOVES::RIGHT, '\0'},
            {MOVES::EXIT,  '\0'}
    };
    const std::map<MOVES, char> control_default = {
            {MOVES::UP,    'w'},
            {MOVES::DOWN,  'a'},
            {MOVES::LEFT,  's'},
            {MOVES::RIGHT, 'd'},
            {MOVES::EXIT,  'q'}
    };
};


#endif //MAIN_CPP_CONTROLCONFIG_H
