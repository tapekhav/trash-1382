#ifndef SURVIVAL_GAME_H
#define SURVIVAL_GAME_H

#include "Logging/Handle.h"
#include "Enums.h"

class Game : public Handle {
public:
	void StartGame() const;

	void SetGameProgress(bool val) { mGameProgress = val; }
private:
	bool mGameProgress;
	int mMove;
};

#endif //SURVIVAL_GAME_H