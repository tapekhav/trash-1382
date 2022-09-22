#include "Logging/Game.h"

void Game::StartGame() const{
	mMediator->Notify(FIELD_SIZE);
	mMediator->Notify(GAME_PROGRESS);
	while (mGameProgress) {
		mMediator->Notify(DO_CMD);
		mMediator->Notify(GAME_PROGRESS);
	}
	mMediator->Notify(FINISH);
}