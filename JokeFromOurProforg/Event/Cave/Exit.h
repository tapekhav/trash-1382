#ifndef SURVIVE_EXIT_H
#define SURVIVE_EXIT_H

#include "Event/Cave/Cave.h"
#include "Logging/Mediator.h"

class Exit : public Cave {
public:
	Exit(Mediator* mediator) : mMediator(mediator){}

	bool Happen() override;
	EnumClass::Events GetStatus() override;
private:
	Mediator* mMediator;
};

#endif //SURVIVE_EXIT_H