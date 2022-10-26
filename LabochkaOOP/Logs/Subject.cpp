//
// Created by corvussharp on 26.10.22.
//


#include "Subject.h"

void Subject::attach(Observer *observer) {
    observers.push_back(observer);
}

void Subject::detach(Observer *observer) {
    std::remove(observers.begin(), observers.end(), observer);
}

void Subject::notify() {
    for (auto i:observers) {
        i->update();
    }
}
