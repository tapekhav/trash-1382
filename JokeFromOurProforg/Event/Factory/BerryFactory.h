#ifndef SURVIVE_BERRYFACTORY_H
#define SURVIVE_BERRYFACTORY_H

#include "Event/Factory/Factory.h"
#include "Event/Bush/BerryBush.h"

class BerryFactory : public Factory {
public:
	BerryFactory(Player *player) : mPlayer(player) { }
	Event* CreateEvent() override { return new BerryBush(mPlayer); }
private:
	Player* mPlayer;
};

#endif //SURVIVE_BERRYFACTORY_H