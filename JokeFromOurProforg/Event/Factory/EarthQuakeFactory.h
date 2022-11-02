#ifndef SURVIVE_EARTHQUAKE_FACTORY_H
#define SURVIVE_EARTHQUAKE_FACTORY_H

#include "Event/Cave/EarthQuakeCave.h"
#include "Event/Factory/Factory.h"

class EarthQuakeFactory : public Factory {
public:
	EarthQuakeFactory(Field* field): mField(field){}

	Event* CreateEvent() override { Message* msg = new StatusDecorator(new Message("Created EarthQuakeCave"));
									Notify(msg);
									delete msg; 
									return new EarthQuakeCave(mField); }
private:
	Field* mField;
};

#endif //SURVIVE_EARTHQUAKE_FACTORY_H