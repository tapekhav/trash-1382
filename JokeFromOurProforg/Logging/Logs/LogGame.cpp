#include "Logging/Logs/LogGame.h"

void LogGame::Update(Message const* msg) {
	if (msg->GetType() == EnumClass::LOG_GAME)
		for (auto source : mOutputers)
			source->PrintMsg(msg);
}
