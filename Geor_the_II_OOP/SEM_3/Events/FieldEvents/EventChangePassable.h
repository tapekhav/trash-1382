#pragma once
#include "EventFieldVirtual.h"
#include <map>
class EventChangePassable : public EventFieldVirtual{
    protected:
        std::pair <long int, long int> coord;
        unsigned int radius;
        void set_is_passable(std::pair <long int, long int> left_down, std::pair <long int, long int> right_up, bool type);
    public:
        EventChangePassable(Field *f, std::pair <long int, long int> c, unsigned int r);
        EventChangePassable(Field *f, long int x, long int y, unsigned int r);
        EventChangePassable(Field *f, std::pair <long int, long int> c);
        EventChangePassable(Field *f, long int x, long int y);
        EventChangePassable(Field *f);
        EventChangePassable();
        EventChangePassable(const EventChangePassable& e);
        EventChangePassable(EventChangePassable&& e);
        EventChangePassable& operator=(const EventChangePassable& e);
        EventChangePassable& operator=(EventChangePassable&& e);
        virtual GameStatus trigger() = 0;
        void set_coord(std::pair <long int, long int> c);
        void set_coord(long int x, long int y);
        void set_radius(unsigned int r);
        std::pair <long int, long int> get_coord();
        unsigned int get_radius();
};