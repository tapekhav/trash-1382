#include "Logging/Logs/LogGame.h"

void LogGame::Update(Message const *msg) {
	mMsg = msg;
}

std::ostream& operator <<(std::ostream& out, const LogGame& logGame) {
	switch (logGame.mMsg->GetLog())
	{
	case EnumClass::LOG_GAME_FIELD_SIZE:
		return out << "[LOG] Field got size";
	case EnumClass::LOG_GAME_DO_STEP:
		out << "[LOG] The game did a step. ";
		return out << "Now " << *((int*)logGame.mMsg->GetData(0)) << " steps have been taken";
	case EnumClass::LOG_GAME_EXIT:
		return out << "[LOG] The game is over";
	case EnumClass::LOG_GAME_LOSE:
		return out << "[LOG] Defeat";
	case EnumClass::LOG_GAME_WON:
		return out << "[LOG] Victory";
	default:
		return out;
	}
}

std::ostream& LogGame::Output(std::ostream& out) {
	return out << *this << std::endl;
}
