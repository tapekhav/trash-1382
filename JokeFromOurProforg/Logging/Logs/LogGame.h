#ifndef SURVIVE_LOGGAME_H
#define SURVIVE_LOGGAME_H

#include "Logging/Observer.h"
#include "Logging/Subject.h"

#include <iostream>

class LogGame : public Observer {
public:
	LogGame() {}
	void Update(Message const *msg) override;
};

#endif //SURVIVE_LOGGAME_H