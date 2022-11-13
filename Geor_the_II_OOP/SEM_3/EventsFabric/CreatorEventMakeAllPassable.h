#pragma once
#include "VirtualCreator.h"
#include "EventMakeAllPassable.h"
class CreatorEventMakeAllPassable: public VirtualCreator{
    CellEvent *create(Field *f);
};