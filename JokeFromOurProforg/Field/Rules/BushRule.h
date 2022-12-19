#ifndef SURVIVE_BUSHRULE_H
#define SURVIVE_BUSHRULE_H

#include "Field/Field.h"
#include "Player/Player.h"
#include "Logging/Logger.h"
#include "Enums.h"

#include "Event/Bush/BearBush.h"
#include "Event/Bush/BerryBush.h"
#include "Event/Bush/RabbitBush.h"
#include "Event/Bush/WolfBush.h"

#include <iostream>

template<int x0, int y0>
class BushRule {
public:
	void operator()(Field* field, Player* player, Logger* log) {
		if (x0 < field->GetWidth() && y0 < field->GetHeight()) {
			srand(time(NULL));
			int pos1 = rand() % 2, pos2 = rand() % 2;
			for (int y = y0 - 1; y <= y0 + 1; y++) {
				for (int x = x0 - 1; x <= x0 + 1; x++) {
					if (x >= 0 && x < field->GetWidth() && y >= 0 && y < field->GetHeight()) {
						field->GetCell(y, x).SetWall(false);
						
						if (x == x0 && y == y0) {
							if (!pos1)
								field->GetCell(y, x).SetEvent(new BearBush(player));
							else
								field->GetCell(y, x).SetEvent(new RabbitBush(player));
							continue;
						}
						
						if (!pos2)
							field->GetCell(y, x).SetEvent(new WolfBush(player));
						else
							field->GetCell(y, x).SetEvent(new BerryBush(player));
					}
				}
			}
		}
	}
};

#endif //SURVIVE_BUSHRULE_H