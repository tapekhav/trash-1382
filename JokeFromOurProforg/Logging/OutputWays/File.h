#ifndef SURVIVE_FILE_H
#define SURVIVE_FILE_H

#include "Logging/OutputWays/CommonSource.h"


#include <fstream>

class File : public CommonSource {
public:
	File();

	void PrintMsg(Message const* msg) override;
	
	~File();

private:
	std::ofstream file;
};

#endif //SURVIVE_FILE_H