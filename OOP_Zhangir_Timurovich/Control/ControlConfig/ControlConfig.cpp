//
// Created by roman on 06.11.2022.
//
#include <iostream>
#include "ControlConfig.h"

void ControlConfig::check_config() {
    std::vector<char> used_chars;
    for (auto elem: control) {
        if (elem.second == '\0') {
            control = control_default;
            return;
        }
        used_chars.push_back(elem.second);
    }
    for (int i = 0; i < (used_chars.size() - 1); i++) {
        for (int j = i + 1; j < used_chars.size(); j++) {
            if (used_chars[i] == used_chars[j]) {
                control = control_default;
                return;
            }
        }
    }
}

MOVES ControlConfig::get_key_config(char move) {
    std::map<MOVES, char>::iterator it = control.begin();
    for (int i = 0; it != control.end(); it++, i++) {
        if (it->second == move) {
            return it->first;
        }
    }
    return NOWHERE;
}

