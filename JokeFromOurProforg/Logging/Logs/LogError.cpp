#include "Logging/Logs/LogError.h"

LogError::LogError(Subject& subject) : mSubject(subject) {
	mSubject.Attach(this);
}

void LogError::Update(Message const &msg) {
	
}

LogError::~LogError() {
	mSubject.Detach(this);
}