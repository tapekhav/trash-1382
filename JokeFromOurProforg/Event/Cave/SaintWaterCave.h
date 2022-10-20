#ifndef SURVIVE_SAINTWATERCAVE_H
#define SURVIVE_SAINTWATERCAVE_H

#include "Event/Cave/Cave.h"

class SaintWaterCave : public Cave {
public:
	SaintWaterCave(Player* player) : mPlayer(player) {}

	bool Happen() override;
	EnumClass::Events GetStatus() override;
private:
	Player* mPlayer;
};


#endif //SURVIVE_SAINTWATERCAVE_H