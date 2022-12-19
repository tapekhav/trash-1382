#include "Config/IConfig.h"

EnumClass::Commands IConfig::GetCommand(char cmd) const {
	auto res = mData.find(cmd);
	if (res == mData.end())
		return EnumClass::Commands::UNKNOWN;
	return res->second;
}

void IConfig::SetDefault() {
	mData['w'] = EnumClass::UP;
	mData['d'] = EnumClass::RIGHT;
	mData['s'] = EnumClass::DOWN;
	mData['a'] = EnumClass::LEFT;
	mData['q'] = EnumClass::QUIT;
	mData['Y'] = EnumClass::YES;
	mData['N'] = EnumClass::NO;
}

char IConfig::LookFor(EnumClass::Commands cmd) {
	for (auto it = mData.begin(); it != mData.end(); it++) {
		if (it->second == cmd)
			return it->first;
	}
}