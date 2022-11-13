#pragma once
#include "../UserInterface/GameStatus.h"
class CellEvent{
    public:
        virtual GameStatus trigger() = 0;
};