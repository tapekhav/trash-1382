#pragma once
#include "GameStatus.h"
class CellEvent{
    public:
        virtual GameStatus trigger() = 0;
};