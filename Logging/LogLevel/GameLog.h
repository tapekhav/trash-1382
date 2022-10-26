#ifndef LABS_GAMELOG_H
#define LABS_GAMELOG_H

#include <vector>
#include <algorithm>
#include "LogLevel.h"
#include "../Logger/FileLog.h"
#include "Subject.h"

class GameLog : public LogLevel {
public:
    explicit GameLog(Subject *subject);
    ~GameLog();

    void update(Logger*, const Message &) override;
private:
    Subject *subject;
};

#endif
