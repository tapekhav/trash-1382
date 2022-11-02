#include "Logging/Logs/LogError.h"

void LogError::Update(Message const* msg) {
	if (msg->GetType() == EnumClass::LOG_ERROR)
		for (auto source : mOutputers)
			source->PrintMsg(msg);
}
