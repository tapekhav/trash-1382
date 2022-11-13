#pragma once
#include "../PlayerEssence/Player.h"
#include "../GameBoard/Field.h"
#include "../Observation/Observer.h"
#include "../GameBoard/FieldView.h"
#include "../CommandReader/CommandReader.h"
#include <cmath>
class FacadePlayer{
    private:
        Player *player;
        Field *field;
        Observer *observer;
        FieldView *view;
        CommandReader *reader;
        GameStatus game_step();
        GameStatus move_player(CommandOperand d);
    public:
        FacadePlayer(Player *p, Field *f, Observer *o, CommandReader *r);
        void player_menu();
        GameStatus game_start();
        ~FacadePlayer();
};
