#ifndef TRASH_1382_SUBJECT_H
#define TRASH_1382_SUBJECT_H

#include "LogLevel.h"
#include "../Logger/Logger.h"
#include "../Logger/ConsoleLog.h"
#include <vector>
#include <algorithm>

class Subject {
public:
    void attach(LogLevel *);

    void detach(LogLevel *);
    void notify(Message msg);
private:
    std::vector<LogLevel *> observers;
};

#endif
