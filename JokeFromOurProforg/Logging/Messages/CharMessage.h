#ifndef SURVIVE_CHAR_MESSAGE_H
#define SURVIVE_CHAR_MESSAGE_H

#include "Logging/Message.h"

class CharMessage : public Message {
public:
	CharMessage(char val, std::string comment);

	friend std::ostream& operator <<(std::ostream& out, const CharMessage& CharMessage);
	void PrintMessage(std::ostream& out) const override { out << *this; }
private:
	char mVal;
};

#endif //SURVIVE_CHAR_MESSAGE_H