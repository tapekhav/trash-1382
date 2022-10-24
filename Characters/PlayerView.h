#ifndef LABS_PLAYERVIEW_H
#define LABS_PLAYERVIEW_H


#include "../Logging/Observer.h"
#include "Player.h"
#include <iostream>

class PlayerView : public Observer {
public:
    explicit PlayerView(Player*);
    void update() override;
private:
    Player* player;
};


#endif
