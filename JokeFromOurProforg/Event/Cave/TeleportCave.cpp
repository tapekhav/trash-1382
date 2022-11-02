#include "Event/Cave/TeleportCave.h"

bool TeleportCave::Happen() {
	Message* msg = new StatusDecorator(new Message("TeleportCave happened"));
	Notify(msg);
	delete msg;

	for (int idy = 0; idy < mField->GetWidth(); idy++) {
		for (int idx = 0; idx < mField->GetHeight(); idx++) {
			if (dynamic_cast<Cave*>(mField->GetCell(idy, idx).GetEvent()) && 
										idy != mField->GetPlayerPositionY() && 
										idx != mField->GetPlayerPositionX()) {
				mField->SetPlayerPositionX(idx);
				mField->SetPlayerPositionY(idy);
				return true;
			}
		}
	}
	return false;
}

EnumClass::Events TeleportCave::GetStatus() {
	return EnumClass::TELEPORT;
}