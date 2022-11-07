#include "ConsoleReader.h"

void ConsoleReader::set_size() {
    std::cout << "Do you want to set a field size\n";
    std::cout << "0 - Yes\n";
    std::cout << "1 - No\n";
    int res;
    std::cin >> res;
    if (res) {
        this->width = 11;
        this->height = 11;
        return;
    }
    std::cout << "Width: ";
    std::cin >> this->width;
    std::cout << "Height: ";
    std::cin >> this->height;
}


int ConsoleReader::get_width() const {
    return this->width;
}

int ConsoleReader::get_height() const {
    return this->height;
}

ConsoleReader::ConsoleReader(ControlConfig* cfg) {
    this->control_config = cfg;
}

void ConsoleReader::set_output() {
    char res;
    std::cout << "Output to: \n";
    std::cout << "0 - File\n";
    std::cout << "1 - Console\n";
    std::cin >> res;
    switch (res) {
        case '0':
            this->outputs.push_back(OUTPUT::CONSOLE);
            this->outputs.push_back(OUTPUT::FILEOUT);
            break;
        case '1': {
            this->outputs.push_back(OUTPUT::CONSOLE);
        }
            break;
    }
}


void ConsoleReader::set_level() {
    char res;
    std::cout << "Logging level: \n";
    std::cout << "0 - Game\n";
    std::cout << "1 - Status\n";
    std::cout << "2 - Errors\n";
    std::cin >> res;
    switch (res) {
        case '0':
            this->levels.push_back(LEVEL::GAME);
            this->levels.push_back(LEVEL::STATUS);
            this->levels.push_back(LEVEL::ERROR);
            break;
        case '1': {
            this->levels.push_back(LEVEL::GAME);
            this->levels.push_back(LEVEL::STATUS);
        }
            break;
        case '2': {
            this->levels.push_back(LEVEL::ERROR);
        }
            break;
    }
}


MOVES ConsoleReader::read_move(LogOutInfo *info) {
    if(!control_config)
        return EXIT;
    char key;
    std::cout << "Move to: \n";
    std::cin >> key;
    return control_config->get_key_config(key);
}


std::vector <OUTPUT> ConsoleReader::get_outputs() {
    return this->outputs;
}

std::vector <LEVEL> ConsoleReader::get_levels() {
    return this->levels;
}

