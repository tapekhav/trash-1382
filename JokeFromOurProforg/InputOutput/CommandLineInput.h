#ifndef SURVIVE_COMMANDLINEINPUT_H
#define SURVIVE_COMMANDLINEINPUT_H

#include "InputOutput/InputData.h"

#include <iostream>

class CommandLineInput : public InputData {
public:
	char GetCommand() const override;
	int GetLevel() const override;
};

#endif //SURVIVE_COMMANDLINEINPUT_H