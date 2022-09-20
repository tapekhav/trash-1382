#include "CommandReader.h"

void CommanderReader::read_height() {
    std::cout << "Введите высоту: ";
    std::cin >> height;
}

void CommanderReader::read_width() {
    std::cout << "Введите ширину: ";
    std::cin >> width;
}

void CommanderReader::read_step() {
    char c;

    std::cout << "Введите направление перемещения игрока(u, d, l, r): ";
    std::cin >> c;
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
            step = Player::EXIT;
            std::cout << "\033[1;31m  _____          __  __ ______    ______      ________ _____  \n"
                         " / ____|   /\\   |  \\/  |  ____|  / __ \\ \\    / /  ____|  __ \\ \n"
                         "| |  __   /  \\  | \\  / | |__    | |  | \\ \\  / /| |__  | |__) |\n"
                         "| | |_ | / /\\ \\ | |\\/| |  __|   | |  | |\\ \\/ / |  __| |  _  / \n"
                         "| |__| |/ ____ \\| |  | | |____  | |__| | \\  /  | |____| | \\ \\ \n"
                         " \\_____/_/    \\_\\_|  |_|______|  \\____/   \\/   |______|_|  \\_\\\n\033[0m";
            break;
        default:
            std::cout << "Вы ввели неправильный символ!\n";
            step = Player::STOP;
            break;
    }

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