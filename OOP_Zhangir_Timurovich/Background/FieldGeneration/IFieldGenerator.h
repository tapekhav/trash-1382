//
// Created by roman on 30.11.2022.
//

#ifndef OOP_ROMA_IFIELDGENERATOR_H
#define OOP_ROMA_IFIELDGENERATOR_H

#include "../Field.h"
#include "Rules/WallSetRule.h"
#include "Rules/HealSetRule.h"

#include "../../Events/EventBuilder.h"

class IFieldGenerator {
public:
    virtual Field *fill(LogOutInfo *info = nullptr, Player *player = nullptr, int width = 10, int
    height = 1) = 0;
};


#endif //OOP_ROMA_IFIELDGENERATOR_H
