#include "Logging/Logs/LogError.h"

void LogError::Update(Message const *msg) {
	mMsg = msg;
}

std::ostream& operator <<(std::ostream& out, const LogError& logError) {
	return out;
}

std::ostream& LogError::Output(std::ostream& out) {
	return out << *this << std::endl;
}

