#ifndef SURVIVE_SUBJECT_H
#define SURVIVE_SUBJECT_H

#include "Logging/Observer.h"

#include <vector>
#include <algorithm>

class Subject {
public:

	void Attach(Observer* observer);
	void Detach(Observer* observer);
	void Notify(Message const &msg);
private:
	std::vector<Observer*> mObservers;
};

#endif //SURVIVE_SUBJECT_H