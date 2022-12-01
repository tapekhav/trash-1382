#include "InputOutput/CommandLineInput.h"

char CommandLineInput::GetCommand() const {
	char cmd;
	std::cin >> cmd;
	return cmd;
}

int CommandLineInput::GetLevel() const {
	int num;
	std::cin >> num;
	return num;
}
