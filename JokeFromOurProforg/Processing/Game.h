#ifndef SURVIVAL_GAME_H
#define SURVIVAL_GAME_H

#include "Processing/Handle.h"
#include "Logging/Subject.h"
#include "Logging/Messages/IntMessage.h"
#include "Logging/Messages/GameDecorator.h"
#include "Enums.h"

class Game : public Handle, public Subject {
public:

	void StartGame();

	void SetGameProgress(bool val) { mGameProgress = val; }
	int GetMove() const { return mMove; }
private:
	bool mGameProgress;
	int mMove;
};

#endif //SURVIVAL_GAME_H