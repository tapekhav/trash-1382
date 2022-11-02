#ifndef SURVIVE_TELEPORTCAVE_H
#define SURVIVE_TELEPORTCAVE_H

#include "Event/Cave/Cave.h"

class TeleportCave : public Cave {
public:
	TeleportCave(Field *field) : mField(field) { }

	bool Happen() override;
	EnumClass::Events GetStatus() override;

	~TeleportCave() {
		Message* msg = new StatusDecorator(new Message("TeleportCave deleted"));
		Notify(msg);
		delete msg;
	}

private:
	Field* mField;
};

#endif //SURVIVE_TELEPORTCAVE_H