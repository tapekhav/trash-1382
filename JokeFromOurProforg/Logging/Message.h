#ifndef SURVIVE_MESSAGE_H
#define SURVIVE_MESSAGE_H

#include "Enums.h"

#include <iostream>

class Message {
public:
	Message() {}
	Message(std::string string) : mString(string), mType(EnumClass::LOG_UNKNOWN) {}

	EnumClass::Log GetType() const { return mType; }
	void SetType(EnumClass::Log type) { mType = type; }

	friend std::ostream& operator <<(std::ostream& out, const Message& message) { return out << message.mString; }

	virtual void PrintMessage(std::ostream& out) const { out << *this; }

protected:
	EnumClass::Log mType;
	std::string mString;
};

#endif //SURVIVE_MESSAGE_H