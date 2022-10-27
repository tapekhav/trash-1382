#include "Logging/Logs/LogError.h"

void LogError::Update(Message const *msg) {
	mMsg = msg;
}

std::ostream& operator <<(std::ostream& out, const LogError& logError) {
	switch (logError.mMsg->GetLog())
	{
	case EnumClass::LOG_ERROR_WALL:
		out << "[ERROR] Attemp to get a cell with wall that stayed on ";
		out << "X coord: " <<  * ((int*)logError.mMsg->GetData(0)) << " ";
		return out << "Y coord: " << *((int*)logError.mMsg->GetData(1));
	case EnumClass::LOG_ERROR_INCORRECT_INPUT:
		return out << "[ERROR] Attemp to enter incorrect values: " << *((char*)logError.mMsg->GetData(0));
	case EnumClass::LOG_ERROR_FIELD_SIZE:
		out << "[ERROR] Attemp to enter incorrent field size : ";
		out << "Width: " << *((int*)logError.mMsg->GetData(0)) << " ";
		return out << "Height: " << *((int*)logError.mMsg->GetData(1));
	default:
		return out;
	}
}

std::ostream& LogError::Output(std::ostream& out) {
	return out << *this << std::endl;
}

