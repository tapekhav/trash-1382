#ifndef SURVIVE_INT_INT_MESSAGE_H
#define SURVIVE_INT_INT_MESSAGE_H

#include "Logging/Message.h"

class IntIntMessage : public Message {
public:
	IntIntMessage(int val1, int val2, std::string string);

	friend std::ostream& operator <<(std::ostream& out, const IntIntMessage& intIntMessage);
	void PrintMessage(std::ostream& out) const override { out << *this; }
private:
	int fVal, sVal;
};

#endif //SURVIVE_INT_INT_MESSAGE_H