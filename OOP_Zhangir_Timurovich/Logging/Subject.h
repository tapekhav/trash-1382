//
// Created by roman on 26.10.2022.
//

#ifndef MAIN_CPP_SUBJECT_H
#define MAIN_CPP_SUBJECT_H
#include "Observer.h"
#include <vector>
#include <algorithm>

class Subject {
public:

    void attach(Observer *observer);

    void detach(Observer *observer);

    void notify();

private:
    std::vector<Observer *> observers;
};


#endif //MAIN_CPP_SUBJECT_H
