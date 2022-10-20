#include "InputOutput/PlayerView.h"

void PlayerViewer::View(Player player) const {
	std::cout << "Your hungry: ";
	ViewProperty(EnumClass::HUNGER, player.GetHunger());
	std::cout << "Your thirst: ";
	ViewProperty(EnumClass::THIRST, player.GetThirst());
	std::cout << "Your health: ";
	for (int idx = 0; idx < player.GetHealth(); idx++)
		std::cout << ChooseView(EnumClass::HEALTH, false) << " ";
	std::cout << std::endl;
}

void PlayerViewer::ViewProperty(EnumClass::Properties type, int val) const {
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

void PlayerViewer::PrintStatus(EnumClass::Events status) {
	std::cout << "Status: ";
	switch (status) {
	case EnumClass::RABBIT:
		std::cout << "You found such a deliciuos rabbit!" << std::endl;
		break;
	case EnumClass::BEAR:
		std::cout << "A bear came out from the bush!" << std::endl;
		break;
	case EnumClass::WOLF:
		std::cout << "A wolf bit you!" << std::endl;
		break;
	case EnumClass::BERRY:
		std::cout << "Some tasty berries for you!" << std::endl;
		break;
	case EnumClass::TELEPORT:
		std::cout << "How did you get here? These caves were connected!" << std::endl;
		break;
	case EnumClass::SAINT_WATER:
		std::cout << "This water of the cave healed you!" << std::endl;
		break;
	case EnumClass::WATER:
		std::cout << "You drank some cave's water" << std::endl;
		break;
	case EnumClass::EARTHQUAKE:
		std::cout << "The ground fell down." << std::endl;
		break;
	default:
		std::cout << "Nothing happened!" << std::endl;
	}
}