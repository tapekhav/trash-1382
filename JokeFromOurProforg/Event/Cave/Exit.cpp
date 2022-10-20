#include "Event/Cave/Exit.h"

bool Exit::Happen() {
	mMediator->Notify(EnumClass::VICTORY);
	return true;
}

EnumClass::Events Exit::GetStatus() {
	return EnumClass::NONE;
}