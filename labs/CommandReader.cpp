#include "CommanderReader.h"


void CommanderReader::read_height() {
    std::cin >> height;
}

void CommanderReader::read_width() {
    std::cin >> width;
}

char CommanderReader::read_step() {
    char c;
    std::cin >> c;

    std::cout << "Введите направление перемещения игрока(u, d, l, r): ";
    switch(c) {
        case 'u':
            step = Player::UP;
            break;
        case 'd':
            step = Player::DOWN;
            break;
        case 'l':
            step = Player::LEFT;
            break;
        case 'r':
            step = Player::RIGHT;
            break;
        case 'e':
            break;
        default:
            std::cout << "Вы ввели неправильный символ!\n";
            break;
    }

    return c;
}

int CommanderReader::get_height() const {
    return height;
}

int CommanderReader::get_width() const {
    return width;
}

Player::STEP CommanderReader::get_step() const {
    return step;
}