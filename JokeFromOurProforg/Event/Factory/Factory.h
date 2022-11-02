#ifndef SURVIVE_FACTORY_H
#define SURVIVE_FACTORY_H

#include "Event/Event.h"
#include "Logging/Subject.h"
#include "Logging/Message.h"
#include "Logging/Messages/StatusDecorator.h"

class Factory : public Subject{
public:
	virtual Event* CreateEvent() = 0;
};

#endif //SURVIVE_FACTORY_H