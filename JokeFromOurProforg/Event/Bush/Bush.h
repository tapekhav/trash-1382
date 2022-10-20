#ifndef SURVIVE_BUSH_H
#define SURVIVE_BUSH_H

#include "Event/Event.h"
#include "Player/Player.h"

class Bush : public Event {
public:
	Bush(Player* player) : mPLayer(player) {}

	bool Happen() = 0;
	EnumClass::Events GetStatus() = 0;

protected:
	Player* mPLayer;
};

#endif SURVIVE_BUSH_H