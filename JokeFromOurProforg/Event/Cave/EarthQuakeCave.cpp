#include "Event/Cave/EarthQuakeCave.h"

bool EarthQuakeCave::Happen() {

	Message* msg = new StatusDecorator(new Message("EarthQuakeCave happened"));
	Notify(msg);
	delete msg;

	int pos = rand() % 3;
	Factory* factory;
	
	switch (pos) {
	case 0:
		factory = new WaterFactory(mPlayer);
		break;
	case 1:
		factory = new SaintWaterFactory(mPlayer);
		break;
	case 2:
		factory = new TeleportFactory(mField);
		break;
	}

	mField->GetCell((mField->GetPlayerPositionY() + 1) % mField->GetWidth(), mField->GetPlayerPositionX()).SetEvent(factory->CreateEvent());
	mField->GetCell((mField->GetPlayerPositionY() + mField->GetWidth() - 1) % mField->GetWidth(), mField->GetPlayerPositionX()).SetEvent(factory->CreateEvent());
	mField->GetCell(mField->GetPlayerPositionY(), (mField->GetPlayerPositionX() + 1) % mField->GetHeight()).SetEvent(factory->CreateEvent());
	mField->GetCell(mField->GetPlayerPositionY(), (mField->GetPlayerPositionX() + mField->GetHeight() - 1) % mField->GetHeight()).SetEvent(factory->CreateEvent());
	delete factory;
	return true;
}

EnumClass::Events EarthQuakeCave::GetStatus() {
	return EnumClass::EARTHQUAKE;
}
