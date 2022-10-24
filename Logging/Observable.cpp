#include "Observable.h"

void Observable::attach(Observer *observer) {
    observers.push_back(observer);
}

void Observable::detach(Observer *observer) {
    std::remove(observers.begin(), observers.end(), observer);
}

void Observable::notify() {
    for (auto elem : observers)
        elem->update();
}
