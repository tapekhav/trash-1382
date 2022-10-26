#include "Logging/Logs/LogStatus.h"

void LogStatus::Update(Message const *msg) {
	mMsg = msg;
}

std::ostream& operator<<(std::ostream& out, const LogStatus& logStatus)
{
	switch (logStatus.mMsg->GetLog())
	{
	case EnumClass::LOG_HEALTH:
		return out << "Health: " << *((int*)logStatus.mMsg->GetData(0));
	default:
		break;
	}
}
