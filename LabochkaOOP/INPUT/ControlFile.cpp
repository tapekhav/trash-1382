//
// Created by corvussharp on 07.11.22.
//


#include "ControlFile.h"
#include "ControlConfig.h"
#include "iostream"
#include "../LOG/Logging/Logger.h"

ControlFile::~ControlFile() {
    config.close();
}

ControlFile::ControlFile(const std::string &file_name) {
    config.open(file_name, std::ios_base::in);
}

void ControlFile::check_fix_config() {
    std::vector<char> usedChar;
    std::vector<std::string> usedControl;
    std::string tmpStr;

    for (auto elem: empty_config) {
        if (elem.second == '\0') {
            empty_config = default_config;
            return;
        }
        usedChar.push_back(elem.second);
    }
    for (int i = 0; i < (usedChar.size() - 1); i++) {
        for (int j = i + 1; j < usedChar.size(); j++) {
            if (usedChar[i] == usedChar[j]) {
                empty_config = default_config;
                return;
            }
        }
    }
}

CONTROL ControlFile::get_key(char key) {
    for (auto a: empty_config) {
        if (a.second == key)
            return a.first;
    }
    return NOTHING;
}

void ControlFile::read_config() {
    if (!config.is_open()) {
        empty_config = default_config;
        return;
    }
    std::vector<std::string> usedControl;

    std::string tmpStr;
    while (getline(config, tmpStr)) {
        std::string cmd;
        char symControl = '\0';
        std::istringstream stream(tmpStr);
        stream >> cmd >> symControl;
        usedControl.push_back(cmd);
        for (const auto &key: commands) {
            if (cmd == key.first) {
                empty_config[key.second] = symControl;
            }
        }
    }
    for (int i = 0; i < usedControl.size(); ++i) {
        for (int j = 0; j < usedControl.size(); ++j) {
            if (i != j && usedControl.at(i) == usedControl.at(j)) {
                empty_config = default_config;
                break;
            }
            check_fix_config();
        }

    }
}