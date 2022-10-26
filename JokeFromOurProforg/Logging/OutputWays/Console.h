#ifndef SURVIVE_CONSOLE_H
#define SURVIVE_CONSOLE_H

#include "Logging/Decorator.h"

#include <iostream>

class Console : public Decorator {
public:
	Console(Observer* observer) : Decorator(observer) {}

	void Update(Message const *msg) override;

	~Console() { Decorator::~Decorator(); }
};

#endif //SURVIVE_CONSOLE_H