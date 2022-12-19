#ifndef SURVIVE_WALLRULE_H
#define SURVIVE_WALLRULE_H

#include "Field/Field.h"
#include "Player/Player.h"
#include "Logging/Logger.h"
#include "Enums.h"

#include <iostream>

template<int pos>
class WallRule {
public:
	void operator()(Field* field, Player* player, Logger* log) {
		srand(time(NULL));
		
		if (pos >= 5) {
			for (int y = 0; y < field->GetHeight(); y++) {
				for (int x = 0; x < field->GetWidth(); x++) {
					int put = rand() % pos;
					if (!put && x != field->GetPlayerPositionX() && y != field->GetPlayerPositionY())
						field->GetCell(y, x).SetWall(true);
				}
			}
		}
	}
};

#endif //SURVIVE_WALLRULE_H