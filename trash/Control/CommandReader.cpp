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
            notify(Message("Error", "step was entered incorrectly"));
            break;
    }

}

void CommandReader::read_char() {
    std::cout << "Введите 'y', если хотите оставить у поля стандартное значение(10, 10): ";
    std::cin >> choice;
}

char CommandReader::read_choice() {
    char a;
    std::cin >> a;
    return a;
}

std::vector<Logger*> CommandReader::read_loggers() {
    int number;
    std::vector<Logger*> loggers;

    std::cout << "Введите, куда будут выводиться логи (1 - в консоль, 2 - в файл, 3 - в консоль и в файл, другие значения - никуда): ";
    std::cin >> number;

    if (number == 1) {
        loggers.push_back(new ConsoleLog);
    }
    if (number == 2) {
        loggers.push_back(new FileLog(read_file_name()));
    }
    if (number == 3) {
        loggers.push_back(new ConsoleLog);
        loggers.push_back(new FileLog(read_file_name()));
    }

    return loggers;
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
    if (arg < 10 || arg > 25) {
        notify(Message("Error", "the value was entered incorrectly"));
        arg = 10;
    }
}

std::string CommandReader::read_file_name() const {
    std::cout << "Введите имя файла: ";
    std::string file_name;
    std::cin >> file_name;

    return file_name;
}
