#include "ErrorLog.h"

ErrorLog::ErrorLog(Subject *subject) : subject(subject) {
    this->subject->attach(this);
}

ErrorLog::~ErrorLog() {
    this->subject->detach(this);
}

void ErrorLog::update(Message &msg) {
    for (auto elem : loggers) {
        elem->print(msg);
    }
}

void ErrorLog::set_loggers(std::vector<Logger *>& loggers) {
    this->loggers = loggers;
}
