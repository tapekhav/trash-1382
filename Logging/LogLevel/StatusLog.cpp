#include "StatusLog.h"

StatusLog::StatusLog(Subject *subject) : subject(subject) {
    this->subject->attach(this);
}

StatusLog::~StatusLog() {
    this->subject->detach(this);
}

void StatusLog::update(Message &msg) {
    for (auto elem : loggers){
        elem->print(msg);
    }
}

void StatusLog::set_loggers(std::vector<Logger *>& loggers) {
    this->loggers = loggers;
}
