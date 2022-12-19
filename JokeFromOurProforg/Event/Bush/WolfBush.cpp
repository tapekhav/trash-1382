#include "Event/Bush/WolfBush.h"

bool WolfBush::Happen() {
	Message* msg = new StatusDecorator(new Message("WolfBush happened"));
	Notify(msg);
	delete msg;
	mPLayer->DamagePlayer(EnumClass::WOLF_BUSH);
	return true;
}

EnumClass::Events WolfBush::GetStatus() {
	return EnumClass::WOLF;
}