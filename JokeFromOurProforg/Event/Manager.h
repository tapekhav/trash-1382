#ifndef SURVIVE_MANAGER_H
#define SURVIVE_MANAGER_H

#include "Event/Event.h"
#include "Logging/Subject.h"

class Manager : public Subject{
public:
	virtual Event* ChooseEvent() = 0;
	virtual Event* ChooseConcreteEvent(EnumClass::Events event) = 0;
	virtual bool CheckEvent(Event* event) = 0;
	virtual bool UseEvent(Event* event) = 0;

protected:

};

#endif //SURVIVE_MANAGER_H