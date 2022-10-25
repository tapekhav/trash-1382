#ifndef SURVIVE_LOGGAME_H
#define SURVIVE_LOGGAME_H

#include "Logging/Observer.h"
#include "Logging/Subject.h"

#include <iostream>

class LogGame : public Observer {
public:
	LogGame(Subject& subject);

	void Update(Message const &msg) override;
	~LogGame() override;
private:
	Subject& mSubject;
};

#endif //SURVIVE_LOGGAME_H