#include "Event/Bush/WolfBush.h"

bool WolfBush::Happen() {
	mPLayer->DamagePlayer(EnumClass::WOLF_BUSH);
	return true;
}

EnumClass::Events WolfBush::GetStatus() {
	return EnumClass::WOLF;
}