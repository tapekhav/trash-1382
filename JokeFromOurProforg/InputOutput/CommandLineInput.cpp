#include "InputOutput/CommandLineInput.h"

char CommandLineInput::GetCommand() const {
	char cmd;
	std::cin >> cmd;
	return cmd;
}

std::pair<int, int> CommandLineInput::GetFieldSize() const {
	std::pair<int, int> size;
	std::cin >> size.first >> size.second;
	return size;
}
