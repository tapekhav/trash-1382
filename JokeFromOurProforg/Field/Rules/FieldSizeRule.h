#ifndef SURVIVE_FIELDSIZERULE_H
#define SURVIVE_FIELDSIZERULE_H

#include "Field/Field.h"
#include "Player/Player.h"
#include "Logging/Logger.h"
#include "Enums.h"
#include "Event/EventManager.h"

template<int w = EnumClass::STANDARD_SIZE, int h = EnumClass::STANDARD_SIZE>
class FieldSizeRule {
public:
	void operator()(Field* field, Player* player, Logger* log) {
		delete field;
		field = new Field(w, h);
		Manager* events = new EventManager(player, field, log);
		field->SetEventManager(events);
	}
};

#endif //SURVIVE_FIELDSIZERULE_H