#include "Logging/LogManager.h"

LogManager::LogManager() {
	mLogStatus = new LogStatus;
	mLogError = new LogError;
	mLogGame = new LogGame;

	std::cout << "Please, choose one or several log output types." << std::endl;
	std::cout << "The list of the types:" << std::endl;

	std::cout << "Enter 1 -- output to the console" << std::endl;
	std::cout << "Enter 2 -- output to the file" << std::endl;

	std::cout << "if you'd like to use any output type, enter the corresponding number." << std::endl;
	std::cout << "Could enter several numbers, spliting their with a space." << std::endl;

	std::string mString;
	std::getline(std::cin, mString);
	for (char c : mString) {
		if (c == ' ')
			continue;
		if (c == '1') {
			mLogStatus = new Console(mLogStatus);
			mLogError = new Console(mLogError);
			mLogGame = new Console(mLogGame);
		}

	}
	system("cls");
}

LogManager::~LogManager() {
	delete mLogError;
	delete mLogGame;
	delete mLogStatus;
}
