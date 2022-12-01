#ifndef SURVIVE_EARTHQUAKERULE_H
#define SURVIVE_EARTHQUAKERULE_H

#include "Field/Field.h"
#include "Player/Player.h"
#include "Logging/Logger.h"
#include "Enums.h"

#include "Event/Cave/WaterCave.h"
#include "Event/Cave/EarthQuakeCave.h"

template<int x0, int y0>
class EarthQuakeRule {
public:
	void operator()(Field* field, Player* player, Logger* log) {
		if (x0 < field->GetWidth() && y0 < field->GetHeight()) {
			field->GetCell(y0, x0).SetWall(false);
			field->GetCell(y0, x0).SetEvent(new EarthQuakeCave(field, player));

			for (int x = 0; x < field->GetWidth(); x++) {
				field->GetCell(y0, x).SetWall(false);
				field->GetCell(y0, x).SetEvent(new WaterCave(player));
			}

			for (int y = 0; y < field->GetHeight(); y++) {
				field->GetCell(y, x0).SetWall(false);
				field->GetCell(y, x0).SetEvent(new WaterCave(player));
			}
		}
	}
};

#endif //SURVIVE_EARTHQUAKERULE_H