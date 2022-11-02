#include "Processing/Game.h"

void Game::StartGame(){
	mMove = 0;

	Message* msg = new GameDecorator(new Message("Set field size"));
	Notify(msg);
	delete msg;

	mMediator->Notify(EnumClass::FIELD_SIZE);

	while (mGameProgress && mMove < EnumClass::MOVE_COUNT) {

		Message* msg = new GameDecorator(new IntMessage(mMove, "Call a new command on the step"));
		Notify(msg);
		delete msg;

		mMediator->Notify(EnumClass::DO_CMD);
		mMove++;
	}
	if (mGameProgress) {
		mMediator->Notify(EnumClass::VICTORY);

		Message* msg = new GameDecorator(new Message("Set victory"));
		Notify(msg);
		delete msg;
	}
	else {
		Message* msg = new GameDecorator(new Message("Set defeat"));
		Notify(msg);
		delete msg;
	}

	mMediator->Notify(EnumClass::FINISH);
}