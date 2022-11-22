#ifndef LABS_LEVELSTRATEGY_H
#define LABS_LEVELSTRATEGY_H

#include "Field/FieldGenerator.h"


class LevelStrategy {
public:
    virtual Field* generate_level(int, int) const = 0;
    virtual ~LevelStrategy() = default;
};

#endif