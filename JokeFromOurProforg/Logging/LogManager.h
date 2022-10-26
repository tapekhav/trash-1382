#ifndef SURVIVE_LOGMANAGER_H
#define SURVIVE_LOGMANAGER_H

#include "Logging/Logs/LogStatus.h"
#include "Logging/Logs/LogGame.h"
#include "Logging/Logs/LogError.h"
#include "Logging/OutputWays/Console.h"

#include <iostream>

class LogManager {
public:
	LogManager();

	Observer* GetLogStatus() const { return mLogStatus; }
	Observer* GetLogGame() const { return mLogGame; }
	Observer* GetLogError() const { return mLogError; }

	~LogManager();

private:
	Observer* mLogStatus;
	Observer* mLogError;
	Observer* mLogGame;
};

#endif //SURVIVE_LOGMANAGER_H