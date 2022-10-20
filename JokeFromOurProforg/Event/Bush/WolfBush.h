#ifndef SURVIVE_WOLFBUSH_H
#define SURVIVE_WOLFBUSH_H

#include "Event/Bush/Bush.h"

class WolfBush : public Bush {
public:
	WolfBush(Player* player) : Bush(player) {}

	bool Happen() override;

	EnumClass::Events GetStatus() override;
};

#endif //SURVIVE_WOLFBUSH_H