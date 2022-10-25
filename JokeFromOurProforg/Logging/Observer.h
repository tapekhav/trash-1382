#ifndef SURVIVE_OBSERVER_H
#define SURVIVE_OBSERVER_H

#include "Logging/Message.h"

class Observer {
public:
	virtual void Update(Message const &msg) = 0;
	virtual ~Observer() {};
};

#endif //SURVIVE_OBSERVER_H