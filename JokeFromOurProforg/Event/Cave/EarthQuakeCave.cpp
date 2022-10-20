#include "Event/Cave/EarthQuakeCave.h"

bool EarthQuakeCave::Happen() {
	int pos = rand() % 3;
	EnumClass::Events event = EnumClass::EARTHQUAKE;
	
	switch (pos) {
	case 0:
		event = EnumClass::WATER;
		break;
	case 1:
		event = EnumClass::SAINT_WATER;
		break;
	case 2:
		event = EnumClass::TELEPORT;
		break;
	}

	mField->GetCell((mField->GetPlayerPositionY() + 1) % mField->GetWidth(), mField->GetPlayerPositionX()).SetEvent(event);
	mField->GetCell((mField->GetPlayerPositionY() + mField->GetWidth() - 1) % mField->GetWidth(), mField->GetPlayerPositionX()).SetEvent(event);
	mField->GetCell(mField->GetPlayerPositionY(), (mField->GetPlayerPositionX() + 1) % mField->GetHeight()).SetEvent(event);
	mField->GetCell(mField->GetPlayerPositionY(), (mField->GetPlayerPositionX() + mField->GetHeight() - 1) % mField->GetHeight()).SetEvent(event);
	return true;
}

EnumClass::Events EarthQuakeCave::GetStatus() {
	return EnumClass::EARTHQUAKE;
}
