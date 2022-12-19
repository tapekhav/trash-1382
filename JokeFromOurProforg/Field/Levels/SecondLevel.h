#ifndef SURVIVE_SECONDLEVEL_H
#define SURVIVE_SECONDLEVEL_H

#include "Field/Level.h"

class SecondLevel : public Level {
public:
	SecondLevel(Player* player, Logger* log) : mPlayer(player), mLog(log) {}
	Field* GenerateLevel() override {
		Generator<FieldSizeRule<10, 10>,
			PlayerSpawnRule<0, 0>,
			WallRule<30>,
			EarthQuakeRule<5, 5>,
			SaintWaterRule<5, 8>,
			BushRule<3, 3>> build;
		return build.Fill(mPlayer, mLog);
	}
private:
	Player* mPlayer;
	Logger* mLog;

};

#endif //SURVIVE_SECONDLEVEL_H