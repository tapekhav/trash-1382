#include "Logging/OutputWays/Console.h"

void Console::Update(Message const *msg) {
	Decorator::Update(msg);

	if (dynamic_cast<LogStatus*>(mObserver))
		std::cout << *dynamic_cast<LogStatus*>(mObserver) << std::endl;

}
