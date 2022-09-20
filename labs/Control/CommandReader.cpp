#include "CommandReader.h"

void CommandReader::read_size() {
    std::cout << "Введите высоту: ";
    std::cin >> height;
    check(height);

    std::cout << "Введите ширине: ";
    std::cin >> width;
    check(width);
}


void CommandReader::read_step() {
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
            step = Player::STOP;
            break;
    }

}

void CommandReader::read_char() {
    std::cout << "Введите 'y', если хотите оставить у поля стандартное значение(10, 10): ";
    std::cin >> choice;
}

int CommandReader::get_height() const {
    return height;
}

int CommandReader::get_width() const {
    return width;
}

Player::STEP CommandReader::get_step() const {
    return step;
}

char CommandReader::get_char() const {
    return choice;
}

void CommandReader::check(int &arg) {
    if (arg <= 0) {
        std::cout << "Вы ввели величину некорректно. Будет присвоено стандартное значение.\n";
        arg = 1;
    }
}
