//
// Created by roman on 06.11.2022.
//

#include "FileConfig.h"

#include <string>

FileConfig::FileConfig(const std::string &file_name) {
    file.open(file_name, std::ios_base::in);
}

FileConfig::~FileConfig() {
    file.close();
}

void FileConfig::read_config() {
    if (!file.is_open()) {
        control = control_default;
        return;
    }
    std::string str;
    while (getline(file, str)) {
        std::string command;
        char button = '\0';

        std::istringstream stream(str);
        stream >> command >> button;

        if (command == "right=") {
            control[RIGHT] = button;
        }
        if (command == "left=") {
            control[LEFT] = button;
        }
        if (command == "up=") {
            control[UP] = button;
        }
        if (command == "down=") {
            control[DOWN] = button;
        }
        if (command == "exit=") {
            control[EXIT] = button;
        }
    }

    check_config();
}


