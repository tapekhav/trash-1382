#pragma once
#include "Field.h"
#include "Player.h"
#include "Log.h"
#include <string>
#include <sstream>
class Observer{
    private:
        Field *old_field = nullptr;
        Player *old_player = nullptr;
        Log *log;
    public:
        Observer(Log *l);
        ~Observer();
        void set(Field *f, Player *p);
        void set_field(Field *f);
        void set_player(Player *p);
        void log_field_changes(Field *new_field);
        void log_player_changes(Player *new_player);
        void log_trigger_info(Field *field);
        void log_dead_end();
};