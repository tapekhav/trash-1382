#ifndef SURVIVE_BERRYFACTORY_H
#define SURVIVE_BERRYFACTORY_H

#include "Event/Factory/Factory.h"
#include "Event/Bush/BerryBush.h"

class BerryFactory : public Factory {
public:
	BerryFactory(Player *player) : mPlayer(player) { }
	Event* CreateEvent() override { Message* msg = new StatusDecorator(new Message("Created BerryBush"));
									Notify(msg);
									delete msg; 
									return new BerryBush(mPlayer); }
private:
	Player* mPlayer;
};

#endif //SURVIVE_BERRYFACTORY_H