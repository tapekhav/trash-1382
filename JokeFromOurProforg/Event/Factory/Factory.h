#ifndef SURVIVE_FACTORY_H
#define SURVIVE_FACTORY_H

#include "Event/Event.h"

class Factory {
public:
	virtual Event* CreateEvent() = 0;
};

#endif //SURVIVE_FACTORY_H