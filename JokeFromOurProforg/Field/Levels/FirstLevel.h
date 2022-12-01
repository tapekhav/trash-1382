#ifndef SURVIVE_FIRSTLEVEL_H
#define SURVIVE_FIRSTLEVEL_H

#include "Field/Level.h"

class FirstLevel : public Level {
public:
	FirstLevel(Player* player, Logger* log) : mPlayer(player), mLog(log){}
	Field* GenerateLevel() override {
		Generator<FieldSizeRule<5, 5>,
			PlayerSpawnRule<0, 0>,
			WallRule<30>,
			EarthQuakeRule<4, 4>,
			SaintWaterRule<0, 1>,
			BushRule<2, 2>> build;
		
		return build.Fill(mPlayer, mLog);
	}
private:
	Player* mPlayer;
	Logger* mLog;

};

#endif //SURVIVE_FIRSTLEVEL_H