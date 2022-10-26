#include "Logging/Subject.h"

void Subject::Attach(Observer* observer) {
	mObservers.push_back(observer);
}

void Subject::Detach(Observer* observer) {
	std::remove(mObservers.begin(), mObservers.end(), observer);
}

void Subject::Notify(Message const *msg) {
	for (auto elem : mObservers) {
		elem->Update(msg);
	}
}