#include "Event/Bush/BerryBush.h"

bool BerryBush::Happen() {
	mPLayer->SetHunger(EnumClass::BERRY_BUSH);
	return true;
}

EnumClass::Events BerryBush::GetStatus() {
	return EnumClass::BERRY;
}