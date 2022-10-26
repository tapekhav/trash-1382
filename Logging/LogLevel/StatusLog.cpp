#include "StatusLog.h"

StatusLog::StatusLog(Subject *subject) : subject(subject) {
    this->subject->attach(this);
}

StatusLog::~StatusLog() {
    this->subject->detach(this);
}

void StatusLog::update(Logger* log, const Message &msg) {
    log->print(msg);
}
