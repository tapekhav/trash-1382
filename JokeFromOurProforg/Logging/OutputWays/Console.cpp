#include "Logging/OutputWays/Console.h"

void Console::PrintMsg(Message const* msg) {
	msg->PrintMessage(std::cout);
}