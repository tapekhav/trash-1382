#ifndef SURVIVE_ERROR_DECORATOR_H
#define SURVIVE_ERROR_DECORATOR_H

#include "Logging/Decorator.h"

class ErrorDecorator : public Decorator {
public:
	ErrorDecorator(Message* message) : Decorator(message) { SetType(EnumClass::LOG_ERROR); };

	void PrintMessage(std::ostream& out) const override {
		out << "[ERROR] ";
		Decorator::PrintMessage(out);
		out << std::endl;
	}

	~ErrorDecorator() {
		delete mMessage;
	}
};

#endif //SURVIVE_ERROR_DECORATOR_H