#ifndef SURVIVE_DECORATOR_H
#define SURVIVE_DECORATOR_H

#include "Logging/Message.h"

class Decorator : public Message{
public:
	Decorator(Message* message) : mMessage(message) {}

	void PrintMessage(std::ostream& out) const override { mMessage->PrintMessage(out); };
protected:
	Message* mMessage;

};

#endif //SURVIVE_DECORATOR_H