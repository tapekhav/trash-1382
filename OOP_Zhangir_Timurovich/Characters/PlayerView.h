#pragma once

#include "Player.h"
#include <iostream>


class PlayerView {
public:
    explicit PlayerView(Player *other);

    PlayerView() = default;


    void show_chars();


private:
    Player *player_obj;
};

