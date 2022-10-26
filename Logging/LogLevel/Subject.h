#ifndef TRASH_1382_SUBJECT_H
#define TRASH_1382_SUBJECT_H

#include "LogLevel.h"
#include "../Logger/Logger.h"
#include <vector>
#include <algorithm>

class Subject {
public:
    void attach(LogLevel *);
    void attach_logger(Logger *);

    void detach(LogLevel *);
    void notify(const Message& msg);
private:
    std::vector<LogLevel *> observers;
    std::vector<Logger*>      loggers;
};

#endif
