#include "InputOutput/PlayerView.h"

void PlayerViewer::View(Player player) const{
	std::cout << "Your hungry: ";
	ViewProperty(EnumClass::HUNGER, player.GetHunger());
	std::cout << "Your thirst: ";
	ViewProperty(EnumClass::THIRST, player.GetThirst());
	std::cout << "Your health: ";
	for (int idx = 0; idx < player.GetHealth(); idx++)
		std::cout << ChooseView(EnumClass::HEALTH, false) << " ";
	std::cout << std::endl;
}

void PlayerViewer::ViewProperty(EnumClass::Properties type, int val) const{
	for (int idx = 0; idx < val / 2; idx++) {
		std::cout << ChooseView(type, false) << " ";
	}
	if (val % 2 == 1)
		std::cout << ChooseView(type, true);
	std::cout << std::endl;
}

std::string PlayerViewer::ChooseView(EnumClass::Properties property, bool type) const {
	switch (property) {
	case EnumClass::HEALTH:
		return "<3";
	case EnumClass::HUNGER:
		if (type)
			return "h";
		return "H";
	case EnumClass::THIRST:
		if (type)
			return "o";
		return "O";
	}

}