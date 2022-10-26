#pragma once
#include "CellEvent.h"
#include "Field.h"
class EventFieldVirtual : public CellEvent{
    protected:
        Field *field;
    public:
        virtual GameStatus trigger() = 0;
        void set_field(Field *f);
        Field *get_field();
};