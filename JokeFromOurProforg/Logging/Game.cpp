#include "Logging/Game.h"

void Game::StartGame() const{
	mMediator->Notify(EnumClass::FIELD_SIZE);
	mMediator->Notify(EnumClass::GAME_PROGRESS);
	while (mGameProgress) {
		mMediator->Notify(EnumClass::DO_CMD);
		mMediator->Notify(EnumClass::GAME_PROGRESS);
	}
	mMediator->Notify(EnumClass::FINISH);
}