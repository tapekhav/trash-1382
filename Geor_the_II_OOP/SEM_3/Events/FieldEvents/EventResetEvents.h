#pragma once
#include "EventFieldVirtual.h"
#include "../../Сonstructors/SetterCellEvent.h"
class EventResetEvents : public CellEvent{
    private:
        bool is_only_null;
        SetterCellEvent *setter;
    public:
        EventResetEvents(SetterCellEvent *s, bool i);
        EventResetEvents(SetterCellEvent *s);
        EventResetEvents(const EventResetEvents& e);
        EventResetEvents(EventResetEvents&& e);
        EventResetEvents& operator=(const EventResetEvents& e);
        EventResetEvents& operator=(EventResetEvents&& e);
        EventResetEvents& operator=(SetterCellEvent& e);
        GameStatus trigger();
        void set_setter(SetterCellEvent *s);
        void set_is_only_null(bool i);
        SetterCellEvent *get_setter();
        bool get_is_only_null();
};