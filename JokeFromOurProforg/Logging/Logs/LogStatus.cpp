#include "Logging/Logs/LogStatus.h"

LogStatus::LogStatus(Subject& subject) : mSubject(subject) {
	mSubject.Attach(this);
}

void LogStatus::Update(Message const &msg) {
	switch (msg.GetLog())
	{
	case EnumClass::LOG_HUNGER:
		std::cout << (int*)msg.GetData(0) << std::endl;
	default:
		break;
	}
}

LogStatus::~LogStatus() {
	mSubject.Detach(this);
}