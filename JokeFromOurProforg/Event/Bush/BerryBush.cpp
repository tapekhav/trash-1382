#include "Event/Bush/BerryBush.h"

bool BerryBush::Happen() {
	Message* msg = new StatusDecorator(new Message("BerryBush happened"));
	Notify(msg);
	delete msg;
	mPLayer->SetHunger(EnumClass::BERRY_BUSH);
	return true;
}

EnumClass::Events BerryBush::GetStatus() {
	return EnumClass::BERRY;
}