#pragma once
#include "../CellEvent.h"
#include "../../PlayerEssence/Player.h"
class EventPlayerVirtual : public CellEvent{
    protected:
        Player *player;
    public:
        virtual GameStatus trigger() = 0;
        void set_player(Player *p);
        Player *get_player();
};