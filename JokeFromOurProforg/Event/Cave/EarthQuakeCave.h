#ifndef SURVIVE_EARTHQUAKE_CAVE_H
#define SURVIVE_EARTHQUAKE_CAVE_H

#include "Event/Cave/Cave.h"
#include "Event/Factory/SaintWaterFactory.h"
#include "Event/Factory/WaterFactory.h"
#include "Event/Factory/TeleportFactory.h"

class EarthQuakeCave : public Cave {
public:
	EarthQuakeCave(Field* field, Player* player) : mField(field), mPlayer(player) {}

	bool Happen() override;
	EnumClass::Events GetStatus() override;

	~EarthQuakeCave() {
		Message* msg = new StatusDecorator(new Message("EarthQuakeCaves deleted"));
		Notify(msg);
		delete msg;
	}

private:
	Field* mField;
	Player* mPlayer;
};

#endif //SURVIVE_EARTHQUAKE_CAVE_H