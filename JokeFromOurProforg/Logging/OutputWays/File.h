#ifndef SURVIVE_FILE_H
#define SURVIVE_FILE_H

#include "Logging/Decorator.h"

#include <fstream>

class File : public Decorator {
public:
	File(Observer* observer);
	
	void Update(Message const* msg) override;
	std::ostream& Output(std::ostream& out) override;

	~File();

private:
	std::ofstream file;

};

#endif //SURVIVE_FILE_H