#include "CommandReader.h"

void CommandReader::set_size() {
    std::cout << "Do you want to set a field size\n";
    std::cout << "0 - Yes\n";
    std::cout << "1 - No\n";
    int res;
    std::cin >> res;
    if (res) {
        this->width = 15;
        this->height = 15;
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



