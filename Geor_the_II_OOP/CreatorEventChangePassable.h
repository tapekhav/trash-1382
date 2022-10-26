#pragma once
#include "VirtualCreator.h"
#include "EventChangePassable.h"
class CreatorEventChangePassable: public VirtualCreator{
    CellEvent *create(Field *f);
};