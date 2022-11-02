#ifndef SURVIVE_WATERFACTORY_H
#define SURVIVE_WATERFACTORY_H

#include "Event/Factory/Factory.h"
#include "Event/Cave/WaterCave.h"

class WaterFactory : public Factory {
public:
	WaterFactory(Player *player) : mPlayer(player) {}

	Event* CreateEvent() override { Message* msg = new StatusDecorator(new Message("Created WaterCave"));
									Notify(msg);
									delete msg; 
									return new WaterCave(mPlayer); }
private:
	Player* mPlayer;

};

#endif //SURVIVE_WATERFACTORY_H