#ifndef SURVIVE_GENERATOR_H
#define SURVIVE_GENERATOR_H

#include "Field/Field.h"

#include "Field/Rules/FieldSizeRule.h"
#include "Field/Rules/PlayerSpawnRule.h"
#include "Field/Rules/WallRule.h"
#include "Field/Rules/EarthQuakeRule.h"
#include "Field/Rules/SaintWaterRule.h"
#include "Field/Rules/BushRule.h"

template<class... Rules>
class Generator {
public:
	Field* Fill(Player* player, Logger* log) {
		Field* field = new Field;
		(Rules()(field, player, log),...);

		return field;
	}
};

#endif //SURVIVE_GENERATOR_H