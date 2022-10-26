#ifndef TRASH_1382_STATUSLOG_H
#define TRASH_1382_STATUSLOG_H

#include <string>
#include "LogLevel.h"
#include "Subject.h"

class StatusLog : public LogLevel {
public:
    explicit StatusLog(Subject *subject);
    ~StatusLog();

    void update(Logger*, const Message &) override;
private:
    Subject *subject;
};


#endif
