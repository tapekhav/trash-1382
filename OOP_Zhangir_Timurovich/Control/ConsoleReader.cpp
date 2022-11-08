#include "ConsoleReader.h"




ConsoleReader::ConsoleReader(ControlConfig* cfg) {
    this->control_config = cfg;
}







MOVES ConsoleReader::read_move(LogOutInfo *info) {
    if(!control_config)
        return EXIT;
    char key;
    std::cout << "Move to: \n";
    std::cin >> key;
    return control_config->get_key_config(key);
}


