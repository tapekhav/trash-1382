#ifndef SURVIVE_OBSERVER_H
#define SURVIVE_OBSERVER_H

#include "Logging/Message.h"

#include <string>

class Observer {
public:
	virtual void Update(Message const *msg) = 0;

	virtual ~Observer() {};

protected:
	const Message* mMsg;
};

#endif //SURVIVE_OBSERVER_H