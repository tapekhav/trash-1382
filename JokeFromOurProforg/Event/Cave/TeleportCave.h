#ifndef SURVIVE_TELEPORTCAVE_H
#define SURVIVE_TELEPORTCAVE_H

#include "Event/Cave/Cave.h"

class TeleportCave : public Cave {
public:
	TeleportCave(Field *field) : mField(field) { }

	bool Happen() override;
	EnumClass::Events GetStatus() override;
private:
	Field* mField;
};

#endif //SURVIVE_TELEPORTCAVE_H