#include "CommandReader.h"

void CommandReader::set_size() {
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
    std::cin >> res;
    switch (res) {
        case '0':
            this->outputs.push_back(OUTPUT::FILEOUT);
            break;
        case '1': {
            this->outputs.push_back(OUTPUT::FILEOUT);
            this->outputs.push_back(OUTPUT::CONSOLE);
        }
            break;
    }
}


void CommandReader::set_level() {
    char res;
    std::cout << "Logging level: \n";
    std::cout << "0 - Game\n";
    std::cout << "1 - Status\n";
    std::cout << "2 - Errors\n";
    std::cin >> res;
    switch (res) {
        case '0':
            this->levels.push_back(LEVEL::GAME);
            break;
        case '1': {
            this->levels.push_back(LEVEL::GAME);
            this->levels.push_back(LEVEL::STATUS);
        }
            break;
        case '2': {
            this->levels.push_back(LEVEL::GAME);
            this->levels.push_back(LEVEL::STATUS);
            this->levels.push_back(LEVEL::ERROR);
        }
            break;
    }
}


bool CommandReader::set_move(LogOutInfo *info) {
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
        case 'q': {
            Message message(STATUS, "Game over", info);
            notify(message);
            return false;
        }
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

std::vector <OUTPUT> CommandReader::get_outputs() {
    return this->outputs;
}

std::vector <LEVEL> CommandReader::get_levels() {
    return this->levels;
}

