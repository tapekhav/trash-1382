#ifndef LABS_PLAYERVIEW_H
#define LABS_PLAYERVIEW_H


#include "Player.h"
#include <iostream>

class PlayerView {
public:
    explicit PlayerView(Player*);
    void update();
private:
    Player* player;
};


#endif
