#ifndef SURVIVE_EARTHQUAKE_CAVE_H
#define SURVIVE_EARTHQUAKE_CAVE_H

#include "Event/Cave/Cave.h"

class EarthQuakeCave : public Cave {
public:
	EarthQuakeCave(Field* field) : mField(field){}

	bool Happen() override;
	EnumClass::Events GetStatus() override;

	~EarthQuakeCave() {
		Message* msg = new StatusDecorator(new Message("EarthQuakeCaves deleted"));
		Notify(msg);
		delete msg;
	}

private:
	Field* mField;
};

#endif //SURVIVE_EARTHQUAKE_CAVE_H