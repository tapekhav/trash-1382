#ifndef SURVIVE_CAVE_H
#define SURVIVE_CAVE_H

#include "Event/Event.h"
#include "Player/Player.h"
#include "Field/Field.h"

class Cave : public Event {
public:
	bool Happen() = 0;
	EnumClass::Events GetStatus() = 0;
};

#endif SURVIVE_CAVE_H