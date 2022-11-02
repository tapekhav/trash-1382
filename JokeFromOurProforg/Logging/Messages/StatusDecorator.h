#ifndef SURVIVE_STATUS_DECORATOR_H
#define SURVIVE_STATUS_DECORATOR_H

#include "Logging/Decorator.h"

class StatusDecorator : public Decorator {
public:
	StatusDecorator(Message* message) : Decorator(message) { SetType(EnumClass::LOG_STATUS); };
	
	void PrintMessage(std::ostream& out) const override {
		out << "[STATUS] ";
		mMessage->PrintMessage(out);
		out << std::endl;
	}

	~StatusDecorator() {
		delete mMessage;
	}
};

#endif //SURVIVE_STATUS_DECORATOR_H