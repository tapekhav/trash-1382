#pragma once
#include "GameStatus.h"
#include "Player.h"
#include "Field.h"
#include "Observer.h"
#include "FieldView.h"
#include "CommandReader.h"
#include <cmath>
class FacadePlayer{
    private:
        Player *player;
        Field *field;
        Observer *observer;
        FieldView *view;
    public:
        FacadePlayer(Player *p, Field *f, Observer *o);
        GameStatus move_player(Direction d);
        GameStatus game_start();
        GameStatus game_step();
        ~FacadePlayer();
};
