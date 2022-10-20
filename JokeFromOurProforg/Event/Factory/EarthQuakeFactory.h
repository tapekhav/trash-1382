#ifndef SURVIVE_EARTHQUAKE_FACTORY_H
#define SURVIVE_EARTHQUAKE_FACTORY_H

#include "Event/Cave/EarthQuakeCave.h"
#include "Event/Factory/Factory.h"

class EarthQuakeFactory : public Factory {
public:
	EarthQuakeFactory(Field* field): mField(field){}

	Event* CreateEvent() override { return new EarthQuakeCave(mField); }
private:
	Field* mField;
};

#endif //SURVIVE_EARTHQUAKE_FACTORY_H