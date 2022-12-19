#ifndef SURVIVE_LOGGER_H
#define SURVIVE_LOGGER_H

#include "Logging/Message.h"
#include "Logging/Logs/LogStatus.h"
#include "Logging/Logs/LogError.h"
#include "Logging/Logs/LogGame.h"

#include "Logging/OutputWays/Console.h"
#include "Logging/OutputWays/File.h"

#include <string>

class Logger {
public:
	Logger();

	LogStatus* GetStatusLogger() const { return mStatus; }
	LogError* GetErrorLogger() const { return mError; }
	LogGame* GetGameLogger() const { return mGame; }

	~Logger();
private:
	LogStatus* mStatus;
	LogGame* mGame;
	LogError* mError;
};

#endif //SURVIVE_LOGGER_H