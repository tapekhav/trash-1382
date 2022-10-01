#ifndef SURVIVE_PLAYERVIEW_H
#define SURVIVE_PLAYERVIEW_H

#include "Player/Player.h"
#include "Enums.h"

#include <iostream>

class PlayerViewer {
public:
	void View(Player player) const;

private:
	void ViewProperty(EnumClass::Properties type, int val) const;
	std::string ChooseView(EnumClass::Properties property, bool type) const;
};

#endif //SURVIVE_PLAYERVIEW_H