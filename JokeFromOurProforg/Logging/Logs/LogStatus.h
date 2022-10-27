#ifndef SURVIVE_LOGSTATUS_H
#define SURVIVE_LOGSTATUS_H

#include "Logging/Observer.h"
#include "Logging/Subject.h"

#include <iostream>

class LogStatus : public Observer {
public:
	LogStatus() {}

	friend std::ostream& operator <<(std::ostream& out, const LogStatus& logStatus);

	void Update(Message const *msg) override;
	std::ostream& Output(std::ostream& out) override;

	~LogStatus() {}
private:
	std::string EventChoose(EnumClass::Events* event) const;
};

#endif //SURVIVE_LOGSTATUS_H