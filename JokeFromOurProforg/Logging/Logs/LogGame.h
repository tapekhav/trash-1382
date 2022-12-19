#ifndef SURVIVE_LOGGAME_H
#define SURVIVE_LOGGAME_H

#include "Logging/Logs/CommonLog.h"

class LogGame : public CommonLog {
public:
	LogGame(std::vector<CommonSource*>& sources) : CommonLog(sources) {}
	void Update(Message const* msg) override;
};

#endif //SURVIVE_LOGGAME_H