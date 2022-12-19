#ifndef SURVIVE_PLAYERSPAWNRULE_H
#define SURVIVE_PLAYERSPAWNRULE_H

#include "Field/Field.h"
#include "Player/Player.h"
#include "Logging/Logger.h"
#include "Enums.h"

template<int x, int y>
class PlayerSpawnRule {
public:
	void operator()(Field* field, Player* player, Logger* log) {
		if (x < field->GetPlayerPositionX() && y < field->GetPlayerPositionY()) {
			field->GetCell(y, x).SetWall(false);
			field->SetPlayerPositionX(x);
			field->SetPlayerPositionY(y);
		}
	}
};

#endif //SURVIVE_PLAYERSPAWNRULE_H