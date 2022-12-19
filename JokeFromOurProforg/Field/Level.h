#ifndef SURVIVE_LEVEL_H
#define SURVIVE_LEVEL_H

#include "Field/Generator.h"

class Level {
public:
	virtual Field* GenerateLevel() = 0;
	virtual ~Level() {};
};

#endif //SURVIVE_LEVEL_H