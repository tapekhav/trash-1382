#ifndef SURVIVE_SAINTWATERFACTORY_H
#define SURVIVE_SAINTWATERFACTORY_H

#include "Event/Factory/Factory.h"
#include "Event/Cave/SaintWaterCave.h"

class SaintWaterFactory : public Factory {
public:
	SaintWaterFactory(Player* player) : mPlayer(player){ }

	Event* CreateEvent() override {	Message* msg = new StatusDecorator(new Message("Created SaintWaterCave"));
									Notify(msg);
									delete msg; 
									return new SaintWaterCave(mPlayer); }

private:
	Player* mPlayer;
};

#endif //SURVIVE_SAINTWATERFACTORY_H