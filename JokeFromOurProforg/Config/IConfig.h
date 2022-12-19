#ifndef SURVIVE_ICONFIG_H
#define SURVIVE_ICONFIG_H

#include "Enums.h"
#include <map>

class IConfig {
public:
	IConfig() {}

	EnumClass::Commands GetCommand(char cmd) const;
	char LookFor(EnumClass::Commands cmd);

	virtual ~IConfig() {}
protected:
	void SetDefault();

	std::map<char, EnumClass::Commands> mData;
};

#endif //SURVIVE_ICONFIG_H