#ifndef SURVIVE_CONFIG_H
#define SURVIVE_CONFIG_H

#include "Config/IConfig.h"

#include <fstream>
#include <string>
#include <sstream>

class Config : public IConfig {
public:
	Config();

	~Config() override;
private:
	std::ifstream file;
};

#endif //SURVIVE_CONFIG_H