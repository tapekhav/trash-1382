#include "CommandReader.h"


CommandReader::CommandReader() {
    control = new TerminalController;
}

CommandReader::~CommandReader() {
    delete control;
}

void CommandReader::read_size() {
    std::cout << "Введите ширину: ";
    std::cin >> width;
    check(width);

    std::cout << "Введите высоту: ";
    std::cin >> height;
    check(height);
}


void CommandReader::read_step(const std::map<char, Player::STEP>& config) {
    auto elem = config.find(control->get_step());
    if (elem != config.end()) {
        step = elem->second;
        return;
    }
    if (elem == config.end()) {
        step = Player::STEP::STOP;
        notify(Message(Message::Error, "step was entered incorrectly"));
    }
}

char CommandReader::read_char() {
    std::cout << "Введите 'y', если хотите оставить у поля стандартное значение(10, 10): ";
    std::cin >> choice;
    return choice;
}

char CommandReader::get_game_log() {
    std::cout << "Хотите ли вы отслеживать изменения в игре? Если хотите введите 'y'. В противном случае он не будет логироваться. ";
    std::cin >> choice;
    return choice;
}

char CommandReader::get_error_log() {
    std::cout << "Хотите ли вы отслеживать ошибки? Если хотите введите 'y'. В противном случае он не будет логироваться. ";
    std::cin >> choice;
    return choice;
}

char CommandReader::get_status_log() {
    std::cout << "Хотите ли вы отслеживать статус игры? Если хотите введите 'y'. В противном случае он не будет логироваться. ";
    std::cin >> choice;
    return choice;
}

std::vector<Logger*> CommandReader::read_loggers() {
    int number;
    std::vector<Logger*> loggers;

    std::cout << "Введите, куда будут выводиться логи (1 - в консоль, 2 - в файл, 3 - в консоль и в файл): ";
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

std::string CommandReader::read_file_name() const {
    std::cout << "Введите имя файла: ";
    std::string file_name;
    std::cin >> file_name;
    return file_name;
}

char CommandReader::read_config() {
    std::cout << "Введите 'y', если хотите поставить стандартное управление (w, a, s, d, e): ";
    std::cin >> choice;
    return choice;
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

void CommandReader::check(int &arg) {
    if (arg < 10 || arg > 25) {
        notify(Message(Message::Error, "the value was entered incorrectly"));
        arg = 10;
    }
}
