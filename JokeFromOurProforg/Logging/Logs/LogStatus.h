#ifndef SURVIVE_LOGSTATUS_H
#define SURVIVE_LOGSTATUS_H

#include "Logging/Logs/CommonLog.h"

class LogStatus : public CommonLog {
public:
	LogStatus(std::vector<CommonSource*>& sources) : CommonLog(sources) {}
	void Update(Message const* msg) override;
};

#endif //SURVIVE_LOGSTATUS_H