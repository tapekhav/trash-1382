#ifndef LABS_PLAYERVIEW_H
#define LABS_PLAYERVIEW_H


#include "../Control/Observer/Observer.h"
#include "Player.h"
#include <iostream>

class PlayerView : public Observer {
public:
    explicit PlayerView(Player* other);
    void update() override;
private:
    Player* player;
};


#endif
