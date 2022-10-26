#pragma once
#include <string>
#include <random>
#include "CellEvent.h"
class EventCasing : public CellEvent{
    private:
        CellEvent *event;
        std::string name;
        float chance;
    public:
        EventCasing(std::string n, CellEvent *e, float c);
        EventCasing(std::string n, CellEvent *e);
        EventCasing(CellEvent *e, float c);
        EventCasing(CellEvent *e);
        EventCasing(const EventCasing& e);
        EventCasing(EventCasing&& e);
        EventCasing& operator=(const EventCasing& e);
        EventCasing& operator=(EventCasing&& e);
        EventCasing& operator=(CellEvent& e);
        virtual GameStatus trigger();
        void set_event(CellEvent *e);
        void set_name(std::string n);
        void set_chance(float c);
        std::string get_name();
        float get_chance();
        CellEvent *get_event();
};