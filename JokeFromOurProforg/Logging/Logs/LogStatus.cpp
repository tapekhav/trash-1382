#include "Logging/Logs/LogStatus.h"

void LogStatus::Update(Message const *msg) {
	mMsg = msg;
}

std::ostream& operator<<(std::ostream& out, const LogStatus& logStatus)
{
	switch (logStatus.mMsg->GetLog())
	{
	case EnumClass::LOG_HEALTH:
		return out << "[STATUS] Health: " << *((int*)logStatus.mMsg->GetData(0));
	case EnumClass::LOG_HUNGER:
		return out << "[STATUS] Hunger: " << *((int*)logStatus.mMsg->GetData(0));
	case EnumClass::LOG_THIRST:
		return out << "[STATUS] Thirst: " << *((int*)logStatus.mMsg->GetData(0));
	case EnumClass::LOG_TRIGGER_CELL:
		out << "[STATUS] Cell triggered from position that has ";
		out << "X Coord: " << *((int*)logStatus.mMsg->GetData(1)) << " ";
		return out << "Y coord: " << *((int*)logStatus.mMsg->GetData(0));
	case EnumClass::LOG_CREATE_EVENT:
		return out << "[STATUS] Created " << logStatus.EventChoose((EnumClass::Events*)logStatus.mMsg->GetData(0));
	case EnumClass::LOG_ACTIVATE_EVENT:
		return out << "[STATUS] Activated " << logStatus.EventChoose((EnumClass::Events*)logStatus.mMsg->GetData(0));
	case EnumClass::LOG_DESTROY_EVENT:
		return out << "[STATUS] Destroyed " << logStatus.EventChoose((EnumClass::Events*)logStatus.mMsg->GetData(0));
	case EnumClass::LOG_MOVE_PLAYER:
		out << "[STATUS] Player moved on ";
		out << "X Coord: " << *((int*)logStatus.mMsg->GetData(1)) << " ";
		return out << "Y coord: " << *((int*)logStatus.mMsg->GetData(0));
	default:
		return out;
	}
}

std::ostream& LogStatus::Output(std::ostream& out) {
	return out << *this << std::endl;
}

std::string LogStatus::EventChoose(EnumClass::Events* event) const{
	switch (*event)
	{
	case EnumClass::BEAR:
		return "BearBush";
	case EnumClass::RABBIT:
		return "RabbitBush";
	case EnumClass::BERRY:
		return "BerryBush";
	case EnumClass::WOLF:
		return "WolfBush";
	case EnumClass::EARTHQUAKE:
		return "EarthQuakeCave";
	case EnumClass::SAINT_WATER:
		return "SaintWaterCave";
	case EnumClass::TELEPORT:
		return "TeleportCave";
	case EnumClass::WATER:
		return "WaterCave";
	default:
		break;
	}
}
