#ifndef LABS_OBSERVABLE_H
#define LABS_OBSERVABLE_H

#include "Observer.h"
#include <algorithm>

class Observable {
public:
    void Attach(Observer *observer);
    void Detach(Observer *observer);
    void Notify();
private:
    std::vector<Observer*> observers;
};


#endif
