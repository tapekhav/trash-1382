#include "Logging/Messages/IntIntMessage.h"

IntIntMessage::IntIntMessage(int val1, int val2, std::string string) : Message(string), fVal(val1), sVal(val2) {}

std::ostream& operator <<(std::ostream& out, const IntIntMessage& intIntMessage) {
	return out << intIntMessage.mString << ": " << intIntMessage.fVal << " " << intIntMessage.sVal;
}