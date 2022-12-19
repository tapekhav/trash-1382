#include "Event/Bush/RabbitBush.h"

bool RabbitBush::Happen() {
	Message* msg = new StatusDecorator(new Message("RabbitBush happened"));
	Notify(msg);
	delete msg;
	mPLayer->SetHunger(EnumClass::RABBIT_BUSH);
	return true;
}

EnumClass::Events RabbitBush::GetStatus() {
	return EnumClass::RABBIT;
}