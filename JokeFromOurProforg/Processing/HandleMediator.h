#ifndef SURVIVAL_HANDLE_MEDIATOR_H
#define SURVIVAL_HANDLE_MEDIATOR_H

#include "Processing/Mediator.h"
#include "InputOutput/InputCenter.h"
#include "Processing/Commander.h"
#include "Processing/Game.h"
#include "Enums.h"

class HandleMediator : public Mediator {
public:
	HandleMediator(Commander *commander, InputCenter *inputCenter, Game *game): mCommander(commander), 
															mInputCenter(inputCenter), mGame(game) {
		mCommander->SetMediator(this);
		mInputCenter->SetMediator(this);
		mGame->SetMediator(this);

	}

	void Notify(EnumClass::Action activity) override;
private:
	Commander* mCommander;
	InputCenter* mInputCenter;
	Game* mGame;
};

#endif //SURVIVAL_HANDLE_MEDIATOR_H