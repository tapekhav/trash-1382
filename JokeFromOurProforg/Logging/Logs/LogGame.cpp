#include "Logging/Logs/LogGame.h"

LogGame::LogGame(Subject& subject) : mSubject(subject) {
	mSubject.Attach(this);
}

void LogGame::Update(Message const &msg) {
}

LogGame::~LogGame() {
	mSubject.Detach(this);
}