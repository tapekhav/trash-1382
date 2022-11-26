//
// Created by corvussharp on 26.10.22.
//

#ifndef LABOCHKAOOP_SUBJECT_H
#define LABOCHKAOOP_SUBJECT_H
#include "Observer.h"

class Subject {
public:

    void attach(Observer *observer);

    void detach(Observer *observer);

    void notify(Message& message);

protected:
    std::vector<Observer *> observers;
};



#endif //LABOCHKAOOP_SUBJECT_H
