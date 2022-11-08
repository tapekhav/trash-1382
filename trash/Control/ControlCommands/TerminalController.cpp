#include "TerminalController.h"

char TerminalController::get_step() {
    char choice;
    std::cout << "Введите символ, отвечающий за управление игрой: ";
    std::cin >> choice;
    return choice;
}

