#ifndef SURVIVE_SUBJECT_H
#define SURVIVE_SUBJECT_H

#include "Logging/Observer.h"

class Subject {
public:
	virtual void Attach(Observer* observer) = 0;
	virtual void Detach(Observer* observer) = 0;
	virtual void Notify() = 0;
};

#endif //SURVIVE_SUBJECT_H