#include "Logging/OutputWays/Console.h"

void Console::Update(Message const *msg) {
	Decorator::Update(msg);
	Output(std::cout);
}

std::ostream& Console::Output(std::ostream& out) {
	return mObserver->Output(out);
}