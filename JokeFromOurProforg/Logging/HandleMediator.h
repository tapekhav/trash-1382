#ifndef SURVIVAL_HANDLE_MEDIATOR_H
#define SURVIVAL_HANDLE_MEDIATOR_H

#include "Logging/Mediator.h"
#include "InputOutput/CommandReader.h"
#include "Logging/Commander.h"
#include "Logging/Game.h"
#include "Enums.h"

class HandleMediator : public Mediator {
public:
	HandleMediator(Commander *commander, CommandReader *commandReader, Game *game): mCommander(commander), 
															mCommandReader(commandReader), mGame(game) {
		mCommander->SetMediator(this);
		mCommandReader->SetMediator(this);
		mGame->SetMediator(this);

	}

	void Notify(EnumClass::Action activity) override;
	void CharMsg(char &cmd) override;
	void PairMsg(std::pair<int, int>& couple) override;

	bool DoCmd() const;
private:
	Commander* mCommander;
	CommandReader* mCommandReader;
	Game* mGame;

	char mApproval;
	std::pair <int, int> mSize;
};

#endif //SURVIVAL_HANDLE_MEDIATOR_H