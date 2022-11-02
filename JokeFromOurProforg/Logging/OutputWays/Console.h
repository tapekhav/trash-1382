#ifndef SURVIVE_CONSOLE_H
#define SURVIVE_CONSOLE_H

#include "Logging/OutputWays/CommonSource.h"

#include <iostream>

class Console : public CommonSource {
public:
	void PrintMsg(Message const* msg) override;
};

#endif //SURVIVE_CONSOLE_H