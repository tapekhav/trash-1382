#ifndef SURVIVE_GAME_DECORATOR_H
#define SURVIVE_GAME_DECORATOR_H

#include "Logging/Decorator.h"

class GameDecorator : public Decorator {
public:
	GameDecorator(Message* message) : Decorator(message) { SetType(EnumClass::LOG_GAME); };

	void PrintMessage(std::ostream& out) const override {
		out << "[GAME] ";
		Decorator::PrintMessage(out);
		out << std::endl;
	}

	~GameDecorator() {
		delete mMessage;
	}

};

#endif //SURVIVE_GAME_DECORATOR_H