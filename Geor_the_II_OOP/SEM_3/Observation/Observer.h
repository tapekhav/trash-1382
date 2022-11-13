#pragma once
#include "../GameBoard/Field.h"
#include "../PlayerEssence/Player.h"
#include "../Logging/Log.h"
#include <string>
#include <sstream>
#include <vector>
class Observer{
    private:
        Field *old_field = nullptr;
        Player *old_player = nullptr;
        std::vector <Log*> logs;
        //MessageLevel current_level = none;
        void send(Message m);
        //void pref(MessageLevel ml);
    public:
        Observer(Log *l);
        Observer(std::vector <Log*> l);
        ~Observer();
        void add_log(Log *l);
        void set(Field *f, Player *p);
        void set_field(Field *f);
        void set_player(Player *p);
        void log_field_changes(Field *new_field);
        void log_player_changes(Player *new_player);
        void log_dead_end();
        void log_start_game();
        void log_finish_game(GameStatus status);
        void log_error(std::string text);
};