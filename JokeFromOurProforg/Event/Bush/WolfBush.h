#ifndef SURVIVE_WOLFBUSH_H
#define SURVIVE_WOLFBUSH_H

#include "Event/Bush/Bush.h"

class WolfBush : public Bush {
public:
	WolfBush(Player* player) : Bush(player) {}

	bool Happen() override;

	EnumClass::Events GetStatus() override;

	~WolfBush() {
		Message* msg = new StatusDecorator(new Message("WolfBush deleted"));
		Notify(msg);
		delete msg;
	}
};

#endif //SURVIVE_WOLFBUSH_H