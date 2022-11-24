#ifndef SURVIVE_INPUTDATA_H
#define SURVIVE_INPUTDATA_H

#include <iostream>

class InputData {
public:
	virtual char GetCommand() const = 0;
	virtual std::pair<int, int> GetFieldSize() const = 0;
};

#endif //SURVIVE_INPUTDATA_H