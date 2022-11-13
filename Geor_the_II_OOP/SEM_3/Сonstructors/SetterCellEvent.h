#pragma once
#include "../GameBoard/Field.h"
#include "../Events/CellEvent.h"
#include <map>
#include <list>
#include <random>
#include <vector>
class SetterCellEvent{
    private:
        Field *field;
        std::vector <std::pair <CellEvent *, unsigned int>> percent_events;
        std::vector <std::pair <CellEvent *, unsigned int>> singular_events;
        unsigned int total_percent = 0;
        unsigned int total_singular = 0;
        void reset_null();
        void reset_all();
    public:
        SetterCellEvent(Field *f);
        SetterCellEvent(const SetterCellEvent& s);
        SetterCellEvent(SetterCellEvent&& s);
        SetterCellEvent& operator=(const SetterCellEvent& s);
        SetterCellEvent& operator=(SetterCellEvent&& s);
        void set_percent_event(CellEvent *e, unsigned int p);
        void set_percent_event(std::pair <CellEvent *, unsigned int> pe);
        void set_singular_event(CellEvent *e, unsigned int s);
        void set_singular_event(std::pair <CellEvent *, unsigned int> se);
        void set_field(Field *f);
        std::pair <CellEvent *, unsigned int> get_percent_event(unsigned int i);
        std::pair <CellEvent *, unsigned int> get_singular_event(unsigned int i);
        unsigned int get_percent_events_amount();
        unsigned int get_singular_events_amount();
        Field *get_field();
        void set(bool is_only_null);
};