#ifndef SURVIVE_WOLFFACTORY_H
#define SURVIVE_WOLFFACTORY_H

#include "Event/Factory/Factory.h"
#include "Event/Bush/WolfBush.h"

class WolfFactory : public Factory {
public:
	WolfFactory(Player* player) : mPlayer(player) {}
	Event* CreateEvent() override { return new WolfBush(mPlayer); }
private:
	Player* mPlayer;
};

#endif //SURVIVE_WOLFFACTOR_H