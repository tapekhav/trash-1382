#pragma once
#include "CellEvent.h"
#include "Player.h"
class VirtualCreator{
    public:
        virtual CellEvent *create(Field *f) = 0;
        virtual CellEvent *create(Player *p) = 0;
};