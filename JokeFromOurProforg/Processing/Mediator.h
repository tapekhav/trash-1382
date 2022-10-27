#ifndef SURVIVAL_MEDIATOR_H
#define SURVIVAL_MEDIATOR_H

#include "Enums.h"
#include "Logging/Subject.h"

#include <iostream>

class Mediator : public Subject{
public:
	virtual void Notify(EnumClass::Action activity) = 0;
	virtual void CharMsg(char &cmd) = 0;
	virtual void PairMsg(std::pair<int, int> &couple) = 0;
};

#endif //SURVIVAL_MEDIATOR_H