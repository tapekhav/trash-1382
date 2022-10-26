#ifndef SURVIVE_DECORATOR_H
#define SURVIVE_DECORATOR_H

#include "Logging/Observer.h"
#include "Logging/Logs/LogError.h"
#include "Logging/Logs/LogGame.h"
#include "Logging/Logs/LogStatus.h"

class Decorator : public Observer {
public:
	Decorator(Observer* observer): mObserver(observer){}
	
	void Update(Message const* msg) override { mObserver->Update(msg); }
	
	~Decorator() { delete mObserver; }
protected:
	Observer* mObserver;
};

#endif //SURVIVE_DECORATOR_H