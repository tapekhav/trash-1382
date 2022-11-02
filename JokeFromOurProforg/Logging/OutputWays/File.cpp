#include "Logging/OutputWays/File.h"

File::File() {
	file.open("..\\..\\..\\..\\logs.txt", std::ofstream::out);
}

void File::PrintMsg(Message const* msg) {
	msg->PrintMessage(file);
}

File::~File() {
	file.close();
}