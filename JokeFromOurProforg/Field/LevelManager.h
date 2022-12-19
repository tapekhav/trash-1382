#ifndef SURVIVE_LEVELMANAGER_H
#define SURVIVE_LEVELMANAGER_H

#include "Field/Levels/FirstLevel.h"
#include "Field/Levels/SecondLevel.h"

class LevelManager {
public:
	LevelManager(int num, Player* player, Logger* log){
		Level* mLevel;
		if (num == 1) {
			mLevel = new FirstLevel(player, log);
		}
		else {
			mLevel = new SecondLevel(player, log);
		}
		mField = mLevel->GenerateLevel();
		delete mLevel;
	}

	Field* GetField() const { return mField; }

	~LevelManager() {
		delete mField;
	}

private:
	Field* mField;
};

#endif //SURVIVE_LEVELMANAGER_H