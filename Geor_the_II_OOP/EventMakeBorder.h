#pragma once
#include "EventFieldVirtual.h"
class EventMakeBorder : public EventFieldVirtual{
    public:
        EventMakeBorder(Field *f);
        GameStatus trigger();
};