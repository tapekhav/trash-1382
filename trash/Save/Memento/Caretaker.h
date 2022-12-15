#ifndef LABS_CARETAKER_H
#define LABS_CARETAKER_H

#include "Memento.h"
#include <iostream>
#include <vector>
#include <fstream>

class Caretaker {
public:
    explicit Caretaker(const std::string&);
    ~Caretaker();

    void save(Memento*);
    void restore();
private:
    int error_code;
    std::fstream file;
};


#endif
