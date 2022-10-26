//
// Created by roman on 26.10.2022.
//

#include "Subject.h"

void Subject::attach(Observer *observer) {
    observers.push_back(observer);
}

void Subject::detach(Observer *observer) {
    std::remove(observers.begin(), observers.end(), observer);
}

void Subject::notify(Message &message) {
    for (auto elem: observers) {
        elem->update(message);
    }
}