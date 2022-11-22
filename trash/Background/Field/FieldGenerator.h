#ifndef LABS_FIELDGENERATOR_H
#define LABS_FIELDGENERATOR_H

#include "Rules/RuleSpawnEventField.h"
#include "Rules/RuleSpawnEventPlayer.h"
#include "Rules/RuleSpawnKeys.h"
#include "Rules/RuleSpawnTrap.h"
#include "Rules/RuleSpawnWalls.h"
#include "Rules/RuleSpawnPlayer.h"
#include "Field.h"

template<class... Rules>
class FieldGenerator {
public:
    Field* fill(int width, int height) {
        auto* field = new Field(width, height);
        (Rules()(*field),...);

        return field;
    }
};


#endif //LABS_FIELDGENERATOR_H
