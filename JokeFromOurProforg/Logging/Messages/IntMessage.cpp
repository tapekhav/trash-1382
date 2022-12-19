#include "Logging/Messages/IntMessage.h"

IntMessage::IntMessage(int val, std::string comment) : Message(comment), mVal(val) {}

std::ostream& operator <<(std::ostream& out, const IntMessage& intMessage) {
	return out << intMessage.mString << " " << intMessage.mVal;
}