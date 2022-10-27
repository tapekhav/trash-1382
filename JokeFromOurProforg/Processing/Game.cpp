#include "Processing/Game.h"

void Game::StartGame(){
	mMove = 0;
	mMediator->Notify(EnumClass::FIELD_SIZE);
	CreateMessage(EnumClass::LOG_GAME_FIELD_SIZE);
	while (mGameProgress && mMove < EnumClass::MOVE_COUNT) {
		mMediator->Notify(EnumClass::DO_CMD);
		mMove++;
		Message* msg = new Message(EnumClass::LOG_GAME_DO_STEP);
		msg->IncreaseData(&mMove);
		Notify(msg);
		delete msg;
	}
	if (mGameProgress) {
		mMediator->Notify(EnumClass::VICTORY);
		CreateMessage(EnumClass::LOG_GAME_WON);
	}
	else
		CreateMessage(EnumClass::LOG_GAME_LOSE);
	CreateMessage(EnumClass::LOG_GAME_EXIT);
	mMediator->Notify(EnumClass::FINISH);
}

void Game::CreateMessage(EnumClass::Log type) {
	Message* msg = new Message(type);
	Notify(msg);
	delete msg;
}