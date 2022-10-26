#include "Observer.h"
Observer::Observer(Log *l) : log(l){}
Observer::~Observer(){
    if(old_field != nullptr){
        delete old_field;
    }
    if(old_player != nullptr){
        delete old_player;
    }
}
void Observer::set(Field *f, Player *p){
    this->set_field(f);
    this->set_player(p);
}
void Observer::set_field(Field *f){
    old_field = new Field;
    *old_field = *f;
    std::stringstream ss;
    ss << "Field:\n\twidth - " << old_field->get_width() << "\n\tlength - " << old_field->get_length() << "\n\tcoord - x:" << old_field->get_coord().first << ", y:" << old_field->get_coord().second << "\n";
    ss << "\tMap:\n";
    for(int x = old_field->get_width() - 1; x >= 0; x--){
        ss << "\t\t";
        for(int y = 0; y < old_field->get_length(); y++){
            ss << "(" << old_field->get_cell(x, y)->get_event() << ", " << old_field->get_cell(x, y)->is_passable() << ") ";
        }
        ss << "\n";
    }
    log->put_field_changes(ss.str());
    ss.clear();
}
void Observer::set_player(Player *p){
    old_player = new Player;
    *old_player = *p;
    std::stringstream ss;
    ss << "Player:\n";
    ss << "\thit_point - " << old_player->get_hit_point() << "\n\tstrength - " << old_player->get_strength() << "\n\tendurance - " << old_player->get_endurance() << "\n\tdexterity - " << old_player->get_dexterity() << "\n\tarmor - " << old_player->get_armor() << "\n\tcoins - " << old_player->get_coins() << "\n";
    log->put_player_changes(ss.str());
    ss.clear();
}
void Observer::log_field_changes(Field *new_field){
    if(old_field == nullptr){
        set_field(new_field);
        return;
    }
    std::stringstream ss;
    if(old_field->get_coord().first != new_field->get_coord().first || old_field->get_coord().second != new_field->get_coord().second){
        ss << "Move From (" << old_field->get_coord().first << ":" << old_field->get_coord().second << ") -> (" << new_field->get_coord().first << ":" << new_field->get_coord().second << ")\n";
    }
    if(*old_field != *new_field){
        if(old_field->get_width() != new_field->get_width() || old_field->get_length() != new_field->get_length()){
            log->put_field_changes("New ");
            this->set_field(new_field);
            return;
        }
        ss << "Field Changes:\n";
        for(int x = old_field->get_width() - 1; x >=0; x--){
            for(int y = 0; y < old_field->get_length(); y++){
                if(old_field->get_cell(x, y) != new_field->get_cell(x, y)){
                    ss << "\t(" << x << ":" << y << ") - (";
                    bool check = false;
                    if(old_field->get_cell(x, y)->is_passable() != new_field->get_cell(x, y)->is_passable()){
                        ss << " " << old_field->get_cell(x, y)->is_passable() << " -> " << new_field->get_cell(x, y)->is_passable();
                        check = true;
                    }
                    if(old_field->get_cell(x, y)->get_event() != new_field->get_cell(x, y)->get_event()){
                        if(check){
                            ss << ',';
                        }
                        ss << " " << old_field->get_cell(x, y)->get_event() << " -> " << new_field->get_cell(x, y)->get_event();
                    }
                    ss << ")";
                }
            }
            ss << "\n";
        }
        log->put_field_changes(ss.str());
        *old_field = *new_field;
    }
    ss.clear();
}
void Observer::log_player_changes(Player *new_player){
    if(old_player == nullptr){
        set_player(new_player);
    }
    if(*old_player != *new_player){
        std::stringstream ss;
        ss << "Player Changes:\n";
        if(old_player->get_hit_point() != new_player->get_hit_point()){
            ss << "\thit_point - " << old_player->get_hit_point()  << " -> " << new_player->get_hit_point() << "\n";
        }
        if(old_player->get_strength() != new_player->get_strength()){
            ss << "\tstrength - " << old_player->get_strength()  << " -> " << new_player->get_strength() << "\n";
        }
        if(old_player->get_endurance() != new_player->get_endurance()){
            ss << "\tendurance - " << old_player->get_endurance()  << " -> " << new_player->get_endurance() << "\n";
        }
        if(old_player->get_dexterity() != new_player->get_dexterity()){
            ss << "\tdexterity - " << old_player->get_dexterity()  << " -> " << new_player->get_dexterity() << "\n";
        }
        if(old_player->get_armor() != new_player->get_armor()){
            ss << "\tarmor - " << old_player->get_armor()  << " -> " << new_player->get_armor() << "\n";
        }
        if(old_player->get_coins() != new_player->get_coins()){
            ss << "\tcoins - " << old_player->get_coins()  << " -> " << new_player->get_coins() << "\n";
        }
        log->put_player_changes(ss.str());
        ss.clear();
        *old_player = *new_player;
    }
}
void Observer::log_trigger_info(Field *field){
    std::stringstream ss;
    if(field->get_player_cell()->get_event()){
        ss << "Event " << field->get_player_cell()->get_event() << " triggered\n";
    }
    else{
        ss << "Null Event " << field->get_event_for_null() << " triggered\n";
    }
    log->put_trigger_info(ss.str());
    ss.clear();
}
void Observer::log_dead_end(){
    log->put_field_changes("Try to step on not passable cell.\n");
}