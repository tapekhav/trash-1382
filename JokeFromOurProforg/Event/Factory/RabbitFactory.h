#ifndef SURVIVE_RABBITFACTORY_H
#define SURVIVE_RABBITFACTORY_H

#include "Event/Factory/Factory.h"
#include "Event/Bush/RabbitBush.h"

class RabbitFactory : public Factory {
public:
	RabbitFactory(Player* player) : mPlayer(player) {}

	Event* CreateEvent() {	Message* msg = new StatusDecorator(new Message("Created RabbitBush"));
							Notify(msg);
							delete msg; 
							return new RabbitBush(mPlayer); }

private:
	Player* mPlayer;
};

#endif //SURVIVE_RABBITFACTORY_H