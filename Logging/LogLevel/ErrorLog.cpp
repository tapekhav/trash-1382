#include "ErrorLog.h"

ErrorLog::ErrorLog(Subject *subject) : subject(subject) {
    this->subject->attach(this);
}

ErrorLog::~ErrorLog() {
    this->subject->detach(this);
}

void ErrorLog::update(const Message &msg) {
    ConsoleLog log;
    log.print(msg);
}
