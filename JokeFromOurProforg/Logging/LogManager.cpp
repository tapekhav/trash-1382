#include "Logging/LogManager.h"

LogManager::LogManager() {
	mLogStatus = new Observer;
	mLogError = new Observer;
	mLogGame = new Observer;
	std::string mString;

	std::cout << "Plase, choose one or several log types." << std::endl;
	std::cout << "If program take an incorrect input from you, it will set default values." << std::endl;
	std::cout << "The list of the types:" << std::endl;

	std::cout << "Enter 1 -- log type that controls Player, Field and events" << std::endl;
	std::cout << "Enter 2 -- log type that controls the status of the game" << std::endl;
	std::cout << "Enter 3 -- log type that controls critical mistakes from a user" << std::endl;

	std::cout << "if you'd like to use any output type, enter the corresponding number." << std::endl;
	std::cout << "Could enter several numbers, spliting their with a space." << std::endl;

	std::getline(std::cin, mString);
	for (char c : mString) {
		if (c == '1') {
			delete mLogStatus;
			mLogStatus = new LogStatus;
		}
		if (c == '2') {
			delete mLogGame;
			mLogGame = new LogGame;
		}
		if (c == '3') {
			delete mLogError;
			mLogError = new LogError;
		}

	}
	system("cls");

	std::cout << "Please, choose one or several output types." << std::endl;
	std::cout << "The list of the types:" << std::endl;

	std::cout << "Enter 1 -- output to the console" << std::endl;
	std::cout << "Enter 2 -- output to the file" << std::endl;
	

	std::cout << "if you'd like to use any output type, enter the corresponding number." << std::endl;
	std::cout << "Could enter several numbers, spliting their with a space." << std::endl;

	std::getline(std::cin, mString);
	for (char c : mString) {
		if (c == '1') {
			mLogStatus = new Console(mLogStatus);
			mLogError = new Console(mLogError);
			mLogGame = new Console(mLogGame);
		}
		if (c == '2') {
			mLogStatus = new File(mLogStatus);
			mLogError = new File(mLogError);
			mLogGame = new File(mLogGame);
		}

	}
	system("cls");
}

LogManager::~LogManager() {
	delete mLogError;
	delete mLogGame;
	delete mLogStatus;
}
