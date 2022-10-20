#ifndef SURVIVE_TELEPORTFACTORY_H
#define SURVIVE_TELEPORTFACTORY_H

#include "Event/Cave/TeleportCave.h"
#include "Event/Factory/Factory.h"

class TeleportFactory : public Factory {
public:
	TeleportFactory(Field *field) : mField(field) {}

	Event* CreateEvent() override { return new TeleportCave(mField); }
private:
	Field* mField;
};

#endif //SURVIVE_TELEPORTFACTORY_H