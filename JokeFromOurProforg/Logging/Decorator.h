#ifndef SURVIVE_DECORATOR_H
#define SURVIVE_DECORATOR_H

#include "Logging/Observer.h"
#include "Logging/Logs/LogError.h"
#include "Logging/Logs/LogGame.h"
#include "Logging/Logs/LogStatus.h"

class Decorator : public Observer {
public:
	Decorator(Observer* observer);
	
	void Update(Message const* msg) override;
	std::ostream& Output(std::ostream& out) override;

protected:
	Observer* mObserver;
};

#endif //SURVIVE_DECORATOR_H