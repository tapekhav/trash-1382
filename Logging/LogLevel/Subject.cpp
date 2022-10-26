#include "Subject.h"

void Subject::attach(LogLevel *observer) {
    observers.push_back(observer);
}

void Subject::attach_logger(Logger *logger) {
    loggers.push_back(logger);
}

void Subject::detach(LogLevel *observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify(const Message& msg) {
    for (auto elem : observers) {
        for (auto log : loggers)
            elem->update(msg);
    }
}
