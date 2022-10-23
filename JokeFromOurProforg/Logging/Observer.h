#ifndef SURVIVE_OBSERVER_H
#define SURVIVE_OBSERVER_H

#include "Logging/Message.h"

class Observer {
public:
	virtual void Update(Message& msg) = 0;
	virtual ~Observer() = 0;
};

#endif //SURVIVE_OBSERVER_H