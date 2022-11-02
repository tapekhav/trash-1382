#include "Event/Cave/WaterCave.h"

bool WaterCave::Happen() {
	Message* msg = new StatusDecorator(new Message("WaterCave happened"));
	Notify(msg);
	delete msg;

	mPlayer->SetThirst(EnumClass::WATER_CAVE);
	return true;
}

EnumClass::Events WaterCave::GetStatus() {
	return EnumClass::WATER;
}