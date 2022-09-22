#ifndef SURVIVE_HANDLE_H
#define SURVIVE_HANDLE_H

#include "Logging/Mediator.h"

class Handle {
public:
	Handle(Mediator* mediator = nullptr): mMediator(mediator) {}

	void SetMediator(Mediator* mediator) { mMediator = mediator; }
protected:
	Mediator* mMediator;
};

#endif //SURVIVE_HANDLE_H