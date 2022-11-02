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

#include "Logging/Logger.h"
#include "Logging/Subject.h"

#include "Event/Manager.h"
#include "Player/Player.h"
#include "Field/Field.h"
#include "Enums.h"

#include <iostream>
#include <map>


class EventManager : public Manager, public Subject {
public:
	EventManager(Player* player, Field* field, Logger* logger) : isExit(false),
		CaveCount(0), BushCount(0), mStatus(EnumClass::NONE), mLogger(logger),
		mPlayer(player), mField(field) {
		berry = new BerryFactory(mPlayer);
		berry->Attach(mLogger->GetStatusLogger());

		wolf = new WolfFactory(mPlayer);
		wolf->Attach(mLogger->GetStatusLogger());

		bear = new BearFactory(mPlayer);
		bear->Attach(mLogger->GetStatusLogger());

		rabbit = new RabbitFactory(mPlayer);
		rabbit->Attach(mLogger->GetStatusLogger());

		water = new WaterFactory(mPlayer);
		water->Attach(mLogger->GetStatusLogger());

		teleport = new TeleportFactory(mField);
		teleport->Attach(mLogger->GetStatusLogger());

		saintWater = new SaintWaterFactory(mPlayer);
		saintWater->Attach(mLogger->GetStatusLogger());

		earthQuake = new EarthQuakeFactory(mField);
		earthQuake->Attach(mLogger->GetStatusLogger());

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
	Logger* mLogger;

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