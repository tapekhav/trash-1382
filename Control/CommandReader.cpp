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
    const char key_left = 'a';
    const char key_right = 'd';
    const char key_up = 'w';
    const char key_down = 's';
    const char key_exit = 'e';

    std::cout << "Введите направление перемещения игрока(w, a, s, d). Для выхода напишите e: ";
    std::cin >> c;
    switch(c) {
        case key_up:
            step = Player::UP;
            break;
        case key_down:
            step = Player::DOWN;
            break;
        case key_left:
            step = Player::LEFT;
            break;
        case key_right:
            step = Player::RIGHT;
            break;
        case key_exit:
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
        arg = 10;
    }
}