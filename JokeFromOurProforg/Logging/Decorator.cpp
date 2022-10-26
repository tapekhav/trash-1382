#include "Logging/Decorator.h"

Decorator::Decorator(Observer* observer) : mObserver(observer){}

void Decorator::Update(Message const* msg) {
	mObserver->Update(msg);
}

std::ostream& Decorator::Output(std::ostream& out) {
	return out;
}