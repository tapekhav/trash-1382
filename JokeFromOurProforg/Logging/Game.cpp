#include "Logging/Game.h"

void Game::StartGame() const{
	mMediator->Notify(EnumClass::FIELD_SIZE);
	while (mGameProgress) {
		mMediator->Notify(EnumClass::DO_CMD);
	}
	mMediator->Notify(EnumClass::FINISH);
}