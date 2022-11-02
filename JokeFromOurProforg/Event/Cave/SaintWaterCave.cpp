#include "Event/Cave/SaintWaterCave.h"

bool SaintWaterCave::Happen() {
	Message* msg = new StatusDecorator(new Message("SaintWaterCave happened"));
	Notify(msg);
	delete msg;
	mPlayer->HealPlayer(EnumClass::SAINT_WATER_CAVE);
	return true;
}

EnumClass::Events SaintWaterCave::GetStatus() {
	return EnumClass::SAINT_WATER;
}