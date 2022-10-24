#include "Logger/ConsoleLog.h"

void ConsoleLog::print(Message* msg) {
    std::cout << msg << '\n';
}
