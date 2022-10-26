#ifndef SURVIVE_OBSERVER_H
#define SURVIVE_OBSERVER_H

#include "Logging/Message.h"

#include <string>

class Observer {
public:
	virtual void Update(Message const* msg) { return; }
	virtual std::ostream& Output(std::ostream& out) { return out; };
	virtual ~Observer() {};

protected:
	const Message* mMsg;
};

#endif //SURVIVE_OBSERVER_H