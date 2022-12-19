#include "Config/Config.h"

Config::Config() {
	file.open("..\\..\\..\\..\\config.txt", std::fstream::in);
	SetDefault();
	std::string str, prefix;
	char command = '\0';
	while (getline(file, str)) {
		std::istringstream stream(str);
		stream >> prefix >> command;

		if (prefix == "dir_right" && command) {
			mData.erase(LookFor(EnumClass::RIGHT));
			mData[command] = EnumClass::RIGHT;
		}
		else if (prefix == "dir_left" && command) {
			mData.erase(LookFor(EnumClass::LEFT));
			mData[command] = EnumClass::LEFT;
		}
		else if (prefix == "dir_up" && command) {
			mData.erase(LookFor(EnumClass::UP));
			mData[command] = EnumClass::UP;
		}
		else if (prefix == "dir_down" && command) {
			mData.erase(LookFor(EnumClass::DOWN));
			mData[command] = EnumClass::DOWN;
		}
		else if (prefix == "quit" && command) {
			mData.erase(LookFor(EnumClass::QUIT));
			mData[command] = EnumClass::QUIT;
		}
	}
}

Config::~Config() {
	file.close();
}