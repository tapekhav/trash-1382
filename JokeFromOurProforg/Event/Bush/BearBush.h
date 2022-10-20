#ifndef SURVIVE_BEARBUSH_H
#define SURVIVE_BEARBUSH_H

#include "Event/Bush/Bush.h"

class BearBush : public Bush {
public:
	BearBush(Player* player) : Bush(player) {}

	bool Happen() override;

	EnumClass::Events GetStatus() override;

};

#endif //SURVIVE_BEARBUSH_H