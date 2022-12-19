#ifndef SURVIVAL_MEDIATOR_H
#define SURVIVAL_MEDIATOR_H

#include "Enums.h"

#include <iostream>

class Mediator {
public:
	virtual void Notify(EnumClass::Action activity) = 0;
};

#endif //SURVIVAL_MEDIATOR_H