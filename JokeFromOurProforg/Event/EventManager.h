#ifndef SURVIVE_EVENTMANAGER_H
#define SURVIVE_EVENTMANAGER_H

#include "Event/Factory/BerryFactory.h"
#include "Event/Factory/WolfFactory.h"
#include "Event/Factory/BearFactory.h"
#include "Event/Factory/RabbitFactory.h"
#include "Event/Factory/WaterFactory.h"
#include "Event/Factory/TeleportFactory.h"
#include "Event/Factory/SaintWaterFactory.h"
#include "Event/Factory/EarthQuakeFactory.h"

#include "Event/Manager.h"
#include "Player/Player.h"
#include "Field/Field.h"
#include "Enums.h"

#include <iostream>
#include <map>


class EventManager : public Manager {
public:
	EventManager(Player* player, Field* field) : isExit(false),
		CaveCount(0), BushCount(0), mStatus(EnumClass::NONE),
		mPlayer(player), mField(field) {
		berry = new BerryFactory(mPlayer);
		wolf = new WolfFactory(mPlayer);
		bear = new BearFactory(mPlayer);
		rabbit = new RabbitFactory(mPlayer);
		water = new WaterFactory(mPlayer);
		teleport = new TeleportFactory(mField);
		saintWater = new SaintWaterFactory(mPlayer);
		earthQuake = new EarthQuakeFactory(mField);

	}

	Event* ChooseEvent() override;
	Event* ChooseConcreteEvent(EnumClass::Events event) override;
	bool UseEvent(Event* event) override;
	bool CheckEvent(Event* event) override;

	EnumClass::Events GetStatus();

	~EventManager() {
		delete berry;
		delete wolf;
		delete bear;
		delete rabbit;
		delete water;
		delete teleport;
		delete saintWater;
		delete earthQuake;
	}

private:
	bool CheckBush();
	bool CheckCave();
	bool isExit;

	EnumClass::Events mStatus;

	void DeleteEvent(Event* event);

	int BushCount;
	int CaveCount;

	std::map<Event*, int> Tracker;

	Field* mField;
	Player* mPlayer;

	BerryFactory* berry;
	WolfFactory* wolf;
	BearFactory* bear;
	RabbitFactory* rabbit;
	WaterFactory* water;
	TeleportFactory* teleport;
	SaintWaterFactory* saintWater;
	EarthQuakeFactory* earthQuake;
};

#endif //SURVIVE_EVENTMANAGER_H