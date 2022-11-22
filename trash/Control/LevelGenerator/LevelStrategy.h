#ifndef LABS_LEVELSTRATEGY_H
#define LABS_LEVELSTRATEGY_H

#include "Field/FieldGenerator.h"


class LevelStrategy {
public:
    virtual ~LevelStrategy() = default;
    virtual Field* generate_level() const = 0;
};

#endif