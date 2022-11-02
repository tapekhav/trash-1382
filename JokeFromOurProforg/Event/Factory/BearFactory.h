#ifndef SURVIVE_BEARFACTORY_H
#define SURVIVE_BEARFACTORY_H

#include "Event/Factory/Factory.h"
#include "Event/Bush/BearBush.h"


class BearFactory : public Factory {
public:
	BearFactory(Player *player) : mPlayer(player) {}

	Event* CreateEvent() override { Message* msg = new StatusDecorator(new Message("Created BearBush"));
									Notify(msg);
									delete msg;
									return new BearBush(mPlayer); }

private:
	Player* mPlayer;
};

#endif //SURVIVE_BEARFACTORY_H