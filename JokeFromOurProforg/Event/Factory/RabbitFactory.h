#ifndef SURVIVE_RABBITFACTORY_H
#define SURVIVE_RABBITFACTORY_H

#include "Event/Factory/Factory.h"
#include "Event/Bush/RabbitBush.h"

class RabbitFactory : public Factory {
public:
	RabbitFactory(Player* player) : mPlayer(player) {}

	Event* CreateEvent() { return new RabbitBush(mPlayer); }

private:
	Player* mPlayer;
};

#endif //SURVIVE_RABBITFACTORY_H