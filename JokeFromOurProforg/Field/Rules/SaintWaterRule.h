#ifndef SURVIVE_SAINTWATERRULE_H
#define SURVIVE_SAINTWATERRULE_H

#include "Field/Field.h"
#include "Player/Player.h"
#include "Logging/Logger.h"
#include "Enums.h"

#include "Event/Cave/SaintWaterCave.h"

template<int x, int y>
class SaintWaterRule {
public:
	void operator()(Field* field, Player* player, Logger* log) {
		if (x < field->GetWidth() && y < field->GetHeight()) {
			field->GetCell(y, x).SetWall(false);
			field->GetCell(y, x).SetEvent(new SaintWaterCave(player));
		}
	}
};

#endif //SURVIVE_SAINTWATERRULE_H