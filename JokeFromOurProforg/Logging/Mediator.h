#ifndef SURVIVAL_MEDIATOR_H
#define SURVIVAL_MEDIATOR_H

#include <iostream>

enum Action {
	FIELD_SIZE,
	GAME_PROGRESS,
	DO_CMD,
	FINISH
};

class Mediator {
public:
	virtual void Notify(Action activity) = 0;
	virtual void CharMsg(char &cmd) = 0;
	virtual void PairMsg(std::pair<int, int> &couple) = 0;
};

#endif //SURVIVAL_MEDIATOR_H