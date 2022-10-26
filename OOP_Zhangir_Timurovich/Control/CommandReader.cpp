#include "CommandReader.h"

void CommandReader::set_size() {
    std::cout << "Do you want to set a field size\n";
    std::cout << "0 - Yes\n";
    std::cout << "1 - No\n";
    int res;
    std::cin >> res;
    if (res) {
        this->width = 10;
        this->height = 10;
        return;
    }
    std::cout << "Width: ";
    std::cin >> this->width;
    std::cout << "Height: ";
    std::cin >> this->height;
}


int CommandReader::get_width() const {
    return this->width;
}

int CommandReader::get_height() const {
    return this->height;
}

CommandReader::CommandReader(int health, int armour, int damage) {
    this->health = health;
    this->armour = armour;
    this->damage = damage;
    this->move = MOVES::NOWHERE;
}

void CommandReader::set_output() {
    char res;
    std::cout << "Output to: \n";
    std::cout << "0 - File\n";
    std::cout << "1 - Console\n";
    std::cout << "2 - Everywhere\n";
    std::cin >> res;
    switch (res) {
        case '0':
            this->outputs.push_back(OUTPUT::FILEOUT);
            break;
        case '1':
            this->outputs.push_back(OUTPUT::CONSOLE);
            break;
        default:
            this->outputs.push_back(OUTPUT::FILEOUT);
            this->outputs.push_back(OUTPUT::CONSOLE);
            break;
    }
}


void CommandReader::set_level() {
    char res;
    std::cout << "Logging level: \n";
    std::cout << "0 - Game\n";
    std::cout << "1 - Status\n";
    std::cout << "2 - Errors\n";
    std::cout << "3 - Game and errors\n";
    std::cout << "4 - Status and errors\n";
    std::cout << "5 - Status and Game\n";
    std::cout << "6 - Everything\n";
    std::cin >> res;
    switch (res) {
        case '0':
            this->levels.push_back(LEVEL::GAME);
            break;
        case '1':
            this->levels.push_back(LEVEL::STATUS);
            break;
        case '2':
            this->levels.push_back(LEVEL::ERROR);
            break;
        case '3':
            this->levels.push_back(LEVEL::GAME);
            this->levels.push_back(LEVEL::ERROR);
            break;
        case '4':
            this->levels.push_back(LEVEL::STATUS);
            this->levels.push_back(LEVEL::ERROR);
            break;
        case '5':
            this->levels.push_back(LEVEL::STATUS);
            this->levels.push_back(LEVEL::GAME);
            break;
        default:
            this->levels.push_back(LEVEL::STATUS);
            this->levels.push_back(LEVEL::GAME);
            this->levels.push_back(LEVEL::ERROR);
            break;
    }
}


bool CommandReader::set_move() {
    char res;
    std::cout << "Move to: \n";
    std::cin >> res;
    switch (res) {
        case 'w':
            this->move = MOVES::UP;
            break;
        case 's':
            this->move = MOVES::DOWN;
            break;
        case 'a':
            this->move = MOVES::LEFT;
            break;
        case 'd':
            this->move = MOVES::RIGHT;
            break;
        case 'q':
            return false;
        default:
            this->move = MOVES::NOWHERE;
            break;
    }
    return true;
}

CommandReader::MOVES CommandReader::get_move() {
    return this->move;
}

std::vector <LEVEL> get_levels();

std::vector <OUTPUT> CommandReader::get_outputs(){
    return this->outputs;
}

std::vector <LEVEL> CommandReader::get_levels(){
    return this->levels;
}

