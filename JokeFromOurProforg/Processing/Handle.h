#ifndef SURVIVE_HANDLE_H
#define SURVIVE_HANDLE_H

#include "Processing/Mediator.h"
#include "Logging/Subject.h"

class Handle : public Subject{
public:
	Handle(Mediator* mediator = nullptr): mMediator(mediator) {}

	void SetMediator(Mediator* mediator) { mMediator = mediator; }
protected:
	Mediator* mMediator;
};

#endif //SURVIVE_HANDLE_H