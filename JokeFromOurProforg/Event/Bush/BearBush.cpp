#include "Event/Bush/BearBush.h"

bool BearBush::Happen() {
	Message* msg = new StatusDecorator(new Message("BearBush happened"));
	Notify(msg);
	delete msg;
	mPLayer->DamagePlayer(EnumClass::BEAR_BUSH);
	return true;
}

EnumClass::Events BearBush::GetStatus() {
	return EnumClass::BEAR;
}