#include "GameLog.h"


GameLog::GameLog(Subject *subject) : subject(subject) {
    this->subject->attach(this);
}

GameLog::~GameLog() {
    this->subject->detach(this);
}

void GameLog::update(Message &msg) {;
    for (auto elem : loggers)
        elem->print(msg);
}

void GameLog::set_loggers(std::vector<Logger *>& loggers) {
    this->loggers = loggers;
}
