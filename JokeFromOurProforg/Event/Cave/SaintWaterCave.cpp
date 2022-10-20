#include "Event/Cave/SaintWaterCave.h"

bool SaintWaterCave::Happen() {
	mPlayer->HealPlayer(EnumClass::SAINT_WATER_CAVE);
	return true;
}

EnumClass::Events SaintWaterCave::GetStatus() {
	return EnumClass::SAINT_WATER;
}