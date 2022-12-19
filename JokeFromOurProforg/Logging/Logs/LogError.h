#ifndef SURVIVE_LOGERROR_H
#define SURVIVE_LOGERROR_H

#include "Logging/Logs/CommonLog.h"

class LogError : public CommonLog {
public:
	LogError(std::vector<CommonSource*>& sources) : CommonLog(sources) {}
	void Update(Message const* msg) override;
};

#endif //SURVIVE_LOGERROR_H