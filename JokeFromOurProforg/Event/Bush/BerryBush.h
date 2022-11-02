#ifndef SURVIVE_BERRYBUSH_H
#define SURVIVE_BERRYBUSH_H

#include "Event/Bush/Bush.h"

class BerryBush : public Bush {
public:
	BerryBush(Player* player) : Bush(player) {}

	bool Happen() override;

	EnumClass::Events GetStatus() override;

	~BerryBush() {
		Message* msg = new StatusDecorator(new Message("BerryBush deleted"));
		Notify(msg);
		delete msg;
	}
};

#endif //SURVIVE_BERRYBUSH_H