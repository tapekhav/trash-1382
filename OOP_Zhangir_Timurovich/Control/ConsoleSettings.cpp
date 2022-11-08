//
// Created by roman on 08.11.2022.
//
#include <iostream>
#include "ConsoleSettings.h"

void ConsoleSettings::set_level() {
    char res;
    std::cout << "Logging level: \n";
    std::cout << "0 - Game\n";
    std::cout << "1 - Status\n";
    std::cout << "2 - Errors\n";
    std::cin >> res;
    switch (res) {
        case '0':
            this->levels.push_back(LEVEL::GAME);
            this->levels.push_back(LEVEL::STATUS);
            this->levels.push_back(LEVEL::ERROR);
            break;
        case '1': {
            this->levels.push_back(LEVEL::GAME);
            this->levels.push_back(LEVEL::STATUS);
        }
            break;
        case '2': {
            this->levels.push_back(LEVEL::ERROR);
        }
            break;
    }
}

void ConsoleSettings::set_output() {
    char res;
    std::cout << "Output to: \n";
    std::cout << "0 - File\n";
    std::cout << "1 - Console\n";
    std::cin >> res;
    switch (res) {
        case '0':
            this->outputs.push_back(OUTPUT::CONSOLE);
            this->outputs.push_back(OUTPUT::FILEOUT);
            break;
        case '1': {
            this->outputs.push_back(OUTPUT::CONSOLE);
        }
            break;
    }
}

void ConsoleSettings::set_size() {
    std::cout << "Do you want to set a field size\n";
    std::cout << "0 - Yes\n";
    std::cout << "1 - No\n";
    int res;
    std::cin >> res;
    if (res) {
        this->width = 11;
        this->height = 11;
        return;
    }
    std::cout << "Width: ";
    std::cin >> this->width;
    std::cout << "Height: ";
    std::cin >> this->height;
}