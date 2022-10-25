#ifndef SURVIVE_LOGSTATUS_H
#define SURVIVE_LOGSTATUS_H

#include "Logging/Observer.h"
#include "Logging/Subject.h"

#include <iostream>

class LogStatus : public Observer {
public:
	LogStatus(Subject& subject);

	void Update(Message const &msg) override;
	~LogStatus() override;
private:
	Subject& mSubject;
};

#endif //SURVIVE_LOGSTATUS_H