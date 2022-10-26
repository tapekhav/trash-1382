#pragma once
#include "VirtualCreator.h"
#include "EventMakeBorder.h"
class CreatorEventMakeBorder: public VirtualCreator{
    CellEvent *create(Field *f);
};