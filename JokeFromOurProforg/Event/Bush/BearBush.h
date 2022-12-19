#ifndef SURVIVE_BEARBUSH_H
#define SURVIVE_BEARBUSH_H

#include "Event/Bush/Bush.h"

class BearBush : public Bush {
public:
	BearBush(Player* player) : Bush(player) {}

	bool Happen() override;

	EnumClass::Events GetStatus() override;

	~BearBush() {
		Message* msg = new StatusDecorator(new Message("BearBush deleted"));
		Notify(msg);
		delete msg;
	}
};

#endif //SURVIVE_BEARBUSH_H