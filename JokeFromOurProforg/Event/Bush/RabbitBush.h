#ifndef SURVIVE_RABBITBUSH_H
#define SURVIVE_RABBITBUSH_H

#include "Event/Bush/Bush.h"

class RabbitBush : public Bush {
public:
	RabbitBush(Player* player) : Bush(player) { }

	bool Happen() override;
	EnumClass::Events GetStatus() override;
};

#endif //SURVIVE_RABBITBUSH_H