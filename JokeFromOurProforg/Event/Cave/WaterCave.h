#ifndef SURVIVE_WATERCAVE_H
#define SURVIVE_WATERCAVE_H

#include "Event/Cave/Cave.h"

class WaterCave : public Cave {
public:
	WaterCave(Player *player) : mPlayer(player) {}

	bool Happen() override;
	EnumClass::Events GetStatus() override;
private:
	Player* mPlayer;
};

#endif //SURVIVE_WATERCAVE_H