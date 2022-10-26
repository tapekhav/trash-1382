#include "Subject.h"

void Subject::attach(LogLevel *observer) {
    observers.push_back(observer);
}

void Subject::detach(LogLevel *observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify(Message msg) {
    for (auto elem : observers) {
        std::cout << "+";
        elem->update(msg);
    }
}
