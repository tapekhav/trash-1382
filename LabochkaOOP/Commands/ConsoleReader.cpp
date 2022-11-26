//
// Created by corvussharp on 22.11.22.
//

#include "ConsoleReader.h"


CONTROL ConsoleReader::read_step() {
    char key;
    std::cout << " Введите команду: ";
    std::cin >> key;
    step = control_config->get_key(key);
    return step;
}

ConsoleReader::ConsoleReader(ControlConfig *cfg) {
    this->control_config = cfg;
}










void ConsoleReader::set_config(ControlConfig *config) {
    control_config = config;
}

CONTROL ConsoleReader::get_step() {
    return step;
}


char ConsoleReader::field_choice() {
    std::cout << "Хотите ли вы изменить размеры поля?\n Если нет Введите 'X' : ";
    std::cin >> sym;
    return sym;
}

char ConsoleReader::get_sym() {
    return sym;
}

