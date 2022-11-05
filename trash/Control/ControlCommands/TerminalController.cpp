#include "TerminalController.h"

char TerminalController::get_command() {
    char sym;
    std::cout << "Введите символ, отвечающий за управление игрой: ";
    std::cin >> sym;
    return sym;
}
