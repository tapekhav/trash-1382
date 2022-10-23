#ifndef SURVIVAL_GAME_H
#define SURVIVAL_GAME_H

#include "Processing/Handle.h"
#include "Enums.h"

class Game : public Handle {
public:

	void StartGame();

	void SetGameProgress(bool val) { mGameProgress = val; }
	int GetMove() const { return mMove; }
private:
	bool mGameProgress;
	int mMove;
};

#endif //SURVIVAL_GAME_H