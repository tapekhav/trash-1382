#ifndef TRASH_1382_ERRORLOG_H
#define TRASH_1382_ERRORLOG_H

#include "Subject.h"

class ErrorLog : public LogLevel {
public:
    explicit ErrorLog(Subject *subject);
    ~ErrorLog();

    void update(Message &) override;
    void set_loggers(std::vector<Logger*>&) override;
private:
    Subject *subject;
};


#endif
