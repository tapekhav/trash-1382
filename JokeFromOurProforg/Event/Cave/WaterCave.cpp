#include "Event/Cave/WaterCave.h"

bool WaterCave::Happen() {
	mPlayer->SetThirst(EnumClass::WATER_CAVE);
	return true;
}

EnumClass::Events WaterCave::GetStatus() {
	return EnumClass::WATER;
}