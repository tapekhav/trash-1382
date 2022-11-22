#include "SecondLevel.h"

Field *SecondLevel::generate_level(int width, int height) {
    FieldGenerator<RuleSpawnKeys<22>,
            RuleSpawnPlayer<0, 0>,
            RuleSpawnEventField<SetWalls, 13>,
            RuleSpawnEventField<DelWalls, 12>,
            RuleSpawnWalls<773>,
            RuleSpawnTrap<88, 5, 10>,
            RuleSpawnEventPlayer<Box, 51>,
            RuleSpawnEventPlayer<Heal, 11>> gen;

    return gen.fill(width, height);
}
