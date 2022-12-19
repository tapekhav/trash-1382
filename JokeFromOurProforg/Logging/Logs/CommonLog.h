#ifndef SURVIVE_COMMONLOG_H
#define SURVIVE_COMMONLOG_H

#include "Logging/Observer.h"
#include "Logging/OutputWays/CommonSource.h"

#include <vector>

class CommonLog : public Observer {
public:
	CommonLog(std::vector<CommonSource*>& sources) : mOutputers(sources) {}
	void Update(Message const* msg) override {}

protected:
	std::vector<CommonSource*> mOutputers;
};

#endif //SURVIVE_COMMONLOG_H