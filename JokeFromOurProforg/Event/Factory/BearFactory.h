#ifndef SURVIVE_BEARFACTORY_H
#define SURVIVE_BEARFACTORY_H

#include "Event/Factory/Factory.h"
#include "Event/Bush/BearBush.h"

class BearFactory : public Factory {
public:
	BearFactory(Player *player) : mPlayer(player) {}

	Event* CreateEvent() override { return new BearBush(mPlayer); }

private:
	Player* mPlayer;
};

#endif //SURVIVE_BEARFACTORY_H