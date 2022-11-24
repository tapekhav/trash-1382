#ifndef SURVIVE_INTMESSAGE_H
#define SURVIVE_INTMESSAGE_H

#include "Logging/Message.h"

class IntMessage : public Message {
public:
	IntMessage(int val, std::string comment);

	friend std::ostream& operator <<(std::ostream& out, const IntMessage& intMessage);
	void PrintMessage(std::ostream& out) const override { out << *this; }
private:
	int mVal;
};

#endif //SURVIVE_INTMESSAGE_H