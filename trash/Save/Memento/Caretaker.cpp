#include "Caretaker.h"


Caretaker::Caretaker(const std::string &file_name) : error_code(0) {
    file.open(file_name, std::ios::app);
    if (!file.is_open()) {
        error_code = 1;
        file.open("save.txt");
    }
}

Caretaker::~Caretaker() {
    file.close();
}

void Caretaker::save(Memento *s) {
    file << s->get_data();
}

void Caretaker::restore() {
    
}
