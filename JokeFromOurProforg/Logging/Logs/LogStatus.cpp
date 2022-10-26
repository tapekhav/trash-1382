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
	case EnumClass::LOG_HUNGER:
		return out << "Hunger: " << *((int*)logStatus.mMsg->GetData(0));
	case EnumClass::LOG_THIRST:
		return out << "Thirst: " << *((int*)logStatus.mMsg->GetData(0));
	default:
		break;
	}
}

std::ostream& LogStatus::Output(std::ostream& out) {
	return out << *this << std::endl;
}
