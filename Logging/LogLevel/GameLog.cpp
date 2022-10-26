#include "GameLog.h"


GameLog::GameLog(Subject *subject) : subject(subject) {
    this->subject->attach(this);
}

GameLog::~GameLog() {
    this->subject->detach(this);
}

void GameLog::update(Logger* logger, const Message &msg) {;
    logger->print(msg);
}
