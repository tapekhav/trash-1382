#include "Logging/OutputWays/File.h"

File::File(Observer* observer) : Decorator(observer) {
	file.open("C:\\Users\\win10\\source\\repos\\Survival\\log.txt", std::ofstream::out);
}

void File::Update(Message const* msg) {
	Decorator::Update(msg);
	Output(file);
}

std::ostream& File::Output(std::ostream& out) {
	return mObserver->Output(out);
}

File::~File() {
	file.close();
}