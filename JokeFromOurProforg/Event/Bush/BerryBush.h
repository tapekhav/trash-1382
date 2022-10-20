#ifndef SURVIVE_BERRYBUSH_H
#define SURVIVE_BERRYBUSH_H

#include "Event/Bush/Bush.h"

class BerryBush : public Bush {
public:
	BerryBush(Player* player) : Bush(player) {}

	bool Happen() override;

	EnumClass::Events GetStatus() override;
};

#endif //SURVIVE_BERRYBUSH_H