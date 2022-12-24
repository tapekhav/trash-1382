//
// Created by corvussharp on 22.11.22.
//

#include <iostream>
#include "ConsoleGameSetings.h"





bool ConsoleGameSetings::valid_arg(int a) {
    if (a <= 0) {
        return false;
    }
    return true;
}
void ConsoleGameSetings::set_size() {
    while (true) {
        std::cout << "Введите Высоту:";
        std::cin >> height;
        std::cout << "Введите ширину:";
        std::cin >> width;
        if (valid_arg(height) && valid_arg(width)) {
            Message message(GAME, "Height: " + std::to_string(height) + "Width: " + std::to_string(width));
            LOG.print(message);
            break;
        }
    }
}
void ConsoleGameSetings::set_output() {
    char res;
    std::cout << "Output to: \n";
    std::cout << "0 - File\n";
    std::cout << "1 - Console\n";
    std::cin >> res;
    switch (res) {
        case '0':
            this->outputs.push_back(OUTPUT::FILEOUT);
            break;
        case '1': {
            this->outputs.push_back(OUTPUT::CONSOLE);
            break;
        }
        case '3':{
            break;
        }
        default:
            this->outputs.push_back(OUTPUT::FILEOUT);
            this->outputs.push_back(OUTPUT::CONSOLE);
            break;
    }
}

void ConsoleGameSetings::set_level() {
    char res;
    std::cout << "Logging level: \n";
    std::cout << "0 - Logging game\n";
    std::cout << "1 - Logging Status\n";
    std::cout << "2 - Logging Errors\n";
    std::cout<<" any - Nothing\n";
    std::cin >> res;
    switch (res) {
        case '0':
            this->levels.push_back(LEVEL::GAME);
            break;
        case '1': {
            this->levels.push_back(LEVEL::GAME);
            this->levels.push_back(LEVEL::STATUS);
            break;
        }
        case '2': {
            this->levels.push_back(LEVEL::GAME);
            this->levels.push_back(LEVEL::STATUS);
            this->levels.push_back(LEVEL::ERROR);
            break;
        }
        default:
            break;
    }
}
