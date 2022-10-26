#include "Logging/Logs/LogGame.h"

void LogGame::Update(Message const *msg) {
	mMsg = msg;
}

std::ostream& operator <<(std::ostream& out, const LogGame& logGame) {
	return out;
}

std::ostream& LogGame::Output(std::ostream& out) {
	return out << *this << std::endl;
}
