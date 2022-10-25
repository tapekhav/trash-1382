#ifndef SURVIVE_LOGERROR_H
#define SURVIVE_LOGERROR_H

#include "Logging/Observer.h"
#include "Logging/Subject.h"

#include <iostream>

class LogError : public Observer {
public:
	LogError(Subject& subject);

	void Update(Message const &msg) override;
	~LogError() override;

private:
	Subject& mSubject;
};

#endif //SURVIVE_LOGERROR_H