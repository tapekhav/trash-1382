#pragma once
#include "EventChangePassable.h"
class EventMakePassable : public EventChangePassable{
    private:
        bool is_player_coord;
    public:
        EventMakePassable(const EventMakePassable& e);
        EventMakePassable(EventMakePassable&& e);
        EventMakePassable& operator=(const EventMakePassable& e);
        EventMakePassable& operator=(EventMakePassable&& e);
        GameStatus trigger();
        void set_is_player_coord(bool i);
        bool get_is_player_coord();
};