#include "Logging/Messages/CharMessage.h"

CharMessage::CharMessage(char val, std::string comment) : Message(comment), mVal(val) {}

std::ostream& operator <<(std::ostream& out, const CharMessage& CharMessage) {
	return out << CharMessage.mString << " " << CharMessage.mVal;
}