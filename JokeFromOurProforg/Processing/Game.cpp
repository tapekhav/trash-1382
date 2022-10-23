#include "Processing/Game.h"

void Game::StartGame(){
	mMove = 0;
	mMediator->Notify(EnumClass::FIELD_SIZE);
	while (mGameProgress && mMove < EnumClass::MOVE_COUNT) {
		mMediator->Notify(EnumClass::DO_CMD);
		mMove++;
	}
	if (mGameProgress)
		mMediator->Notify(EnumClass::VICTORY);
	mMediator->Notify(EnumClass::FINISH);
}