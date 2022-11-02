#include "Logging/Logs/LogStatus.h"

void LogStatus::Update(Message const* msg) {
	if (msg->GetType() == EnumClass::LOG_STATUS)
		for (auto source : mOutputers)
			source->PrintMsg(msg);
}
