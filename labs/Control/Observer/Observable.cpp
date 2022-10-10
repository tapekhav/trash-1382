#include "Observable.h"

void Observable::Attach(Observer *observer) {
    observers.push_back(observer);
}

void Observable::Detach(Observer *observer) {
    std::remove(observers.begin(), observers.end(), observer);
}

void Observable::Notify() {
    for (auto elem : observers)
        elem->update();
}
