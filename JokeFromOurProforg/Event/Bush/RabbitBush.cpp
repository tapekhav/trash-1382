#include "Event/Bush/RabbitBush.h"

bool RabbitBush::Happen() {
	mPLayer->SetHunger(EnumClass::RABBIT_BUSH);
	return true;
}

EnumClass::Events RabbitBush::GetStatus() {
	return EnumClass::RABBIT;
}