#include "Logging/Game.h"

void Game::StartGame(){
	mMove = 0;
	mMediator->Notify(EnumClass::FIELD_SIZE);
	while (mGameProgress && mMove < EnumClass::MOVE_COUNT) {
		mMediator->Notify(EnumClass::DO_CMD);
		mMove++;
	}
	mMediator->Notify(EnumClass::FINISH);
}