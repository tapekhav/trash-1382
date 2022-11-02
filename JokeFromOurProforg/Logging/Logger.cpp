#include "Logging/Logger.h"

Logger::Logger() : mStatus(nullptr), mError(nullptr), mGame(nullptr) {
	std::string mString;
	std::vector<CommonSource*> mOutputers;


	std::cout << "Please, choose one or several output types for logs." << std::endl;
	std::cout << "The list of the types:" << std::endl;

	std::cout << "Enter 1 -- output to the console" << std::endl;
	std::cout << "Enter 2 -- output to the file" << std::endl;


	std::cout << "if you'd like to use any output type, enter the corresponding number." << std::endl;
	std::cout << "Could enter several numbers, spliting their with a space." << std::endl;

	std::getline(std::cin, mString);
	for (char c : mString) {
		if (c == '1') {
			mOutputers.push_back(new Console);
		}
		if (c == '2') {
			mOutputers.push_back(new File);
		}

	}
	system("cls");

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
		if (c == '1' && !mStatus) {
			mStatus = new LogStatus(mOutputers);
		}
		if (c == '2' && !mGame) {
			mGame = new LogGame(mOutputers);
		}
		if (c == '3' && !mError) {
			mError = new LogError(mOutputers);
		}

	}
	system("cls");

	
}

Logger::~Logger() {
	delete mStatus;
}