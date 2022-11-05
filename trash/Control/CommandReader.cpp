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
    TerminalController read_char;
    FileConfig config(read_file_name());
    const auto settings = config.get_config();

    auto elem = settings.find(read_char.get_command());
    if (elem != settings.end()) {
        step = elem->second;
        return;
    }
    if (elem == settings.end()) {
        step = Player::STEP::STOP;
        notify(Message(Message::Error, "step was entered incorrectly"));
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
        notify(Message(Message::Error, "the value was entered incorrectly"));
        arg = 10;
    }
}

std::string CommandReader::read_file_name() const {
    std::cout << "Введите имя файла: ";
    std::string file_name;
    std::cin >> file_name;

    return file_name;
}

char CommandReader::read_config() {
    std::cout << "Введите 'y', если хотите поставить стандартное управление (w, a, s, d, e): ";
    return read_choice();
}
