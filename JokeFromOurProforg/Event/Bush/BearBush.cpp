#include "Event/Bush/BearBush.h"

bool BearBush::Happen() {
	mPLayer->DamagePlayer(EnumClass::BEAR_BUSH);
	return true;
}

EnumClass::Events BearBush::GetStatus() {
	return EnumClass::BEAR;
}