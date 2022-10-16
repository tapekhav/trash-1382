#ifndef LABS_OBSERVABLE_H
#define LABS_OBSERVABLE_H

#include "Observer.h"
#include <algorithm>
#include <vector>

class Observable {
public:
    void attach(Observer *observer);
    void detach(Observer *observer);
    void notify();
private:
    std::vector<Observer*> observers;
};


#endif
