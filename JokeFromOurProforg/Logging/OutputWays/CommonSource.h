#ifndef SURVIVE_COMMONSOURCE_H
#define SURVIVE_COMMONSOURCE_H

#include "Logging/Message.h"

class CommonSource {
public:
	virtual void PrintMsg(Message const* msg) = 0;
};

#endif //SURVIVE_COMMONSOURCE_H