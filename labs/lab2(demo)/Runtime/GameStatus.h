#ifndef LAB2_GAMESTATUS_H
#define LAB2_GAMESTATUS_H


#include "../Background/Field/Field/Field.h"
#include "../Characters/Player.h"

class GameStatus {
public:
    bool isEndGame(Field*, Player*) const;
private:
    bool isWin(Field*, Player*) const;
    bool isLose(Field*, Player*) const;
};


#endif
