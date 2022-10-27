#include "Logging/OutputWays/File.h"

File::File(Observer* observer) : Decorator(observer) {}

void File::Update(Message const* msg) {
	Decorator::Update(msg);
	file.open("C:\\Users\\win10\\source\\repos\\Survival\\log.txt", std::ofstream::app);
	Output(file);
	file.close();
}

std::ostream& File::Output(std::ostream& out) {
	return mObserver->Output(out);
}
