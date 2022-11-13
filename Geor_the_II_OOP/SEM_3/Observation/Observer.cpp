#include "Observer.h"
Observer::Observer(Log *l) : old_field(new Field), old_player(new Player){
    logs.push_back(l);
}
Observer::Observer(std::vector <Log*> l) : logs(l), old_field(new Field), old_player(new Player){}
Observer::~Observer(){
    delete old_field;
    delete old_player;
    logs.clear();
}
void Observer::send(Message m){
    for(Log *l: logs){
        l->out_message(m);
    }
}
/*void Observer::pref(MessageLevel ml){
    if(ml != current_level){
        switch(ml){
            case game_structs_change:
                this->send(Message("GAME STRUCTS CHANGE:\n", ml));
                break;
            case game_status:
                this->send(Message("GAME STRUCTS CHANGE:\n", ml));
                break;
            case error:
                this->send(Message("ERROR:\n", ml));
                break;
            default:
                break;
        }
        current_level = ml;
    }
}*/
void Observer::set(Field *f, Player *p){
    this->set_field(f);
    this->set_player(p);
}
void Observer::set_field(Field *f){
    *old_field = *f;
    std::stringstream ss;
    //this->pref(game_structs_change);
    ss << "\tField:\n\t\twidth - " << old_field->get_width() << "\n\t\tlength - " << old_field->get_length() << "\n\t\tcoord - x:" << old_field->get_coord().first << ", y:" << old_field->get_coord().second << "\n";
    ss << "\t\tMap:\n";
    for(int x = old_field->get_width() - 1; x >= 0; x--){
        ss << "\t\t\t";
        for(int y = 0; y < old_field->get_length(); y++){
            ss << "(" << old_field->get_cell(x, y)->get_event() << ", " << old_field->get_cell(x, y)->is_passable() << ") ";
        }
        ss << "\n";
    }
    this->send(Message(ss.str(), game_structs_change));
    ss.clear();
}
void Observer::set_player(Player *p){
    *old_player = *p;
    std::stringstream ss;
    //this->pref(game_structs_change);
    ss << "\tPlayer:\n";
    ss << "\t\thit_point - " << old_player->get_hit_point() << "\n\t\tstrength - " << old_player->get_strength() << "\n\t\tendurance - " << old_player->get_endurance() << "\n\t\tdexterity - " << old_player->get_dexterity() << "\n\t\tarmor - " << old_player->get_armor() << "\n\t\tcoins - " << old_player->get_coins() << '\n';
    this->send(Message(ss.str(), game_structs_change));
    ss.clear();
}
void Observer::log_field_changes(Field *new_field){
    std::stringstream ss;
    if(old_field->get_coord().first != new_field->get_coord().first || old_field->get_coord().second != new_field->get_coord().second){
        //this->pref(game_structs_change);
        ss << "\tMove From (" << old_field->get_coord().first << ":" << old_field->get_coord().second << ") -> (" << new_field->get_coord().first << ":" << new_field->get_coord().second << ")\n";
        if(old_field->get_player_cell()->get_event()){
            ss << "\tEvent " << old_field->get_player_cell()->get_event() << " triggered\n";
        }
        else{
            ss << "\tNull Event " << old_field->get_event_for_null() << " triggered\n";
        }
    }
    if(*old_field != *new_field){
        //this->pref(game_structs_change);
        if(old_field->get_width() != new_field->get_width() || old_field->get_length() != new_field->get_length()){
            this->set_field(new_field);
            return;
        }
        ss << "\tField Changes:\n";
        for(int x = old_field->get_width() - 1; x >=0; x--){
            ss << "\t\t";
            for(int y = 0; y < old_field->get_length(); y++){
                if(old_field->get_cell(x, y) != new_field->get_cell(x, y)){
                    ss << "(" << x << ":" << y << ") - (";
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
    }
    this->send(Message(ss.str(), game_structs_change));
    *old_field = *new_field;
    ss.clear();
}
void Observer::log_player_changes(Player *new_player){
    if(*old_player != *new_player){
        //this->pref(game_structs_change);
        std::stringstream ss;
        ss << "\tPlayer Changes:\n";
        if(old_player->get_hit_point() != new_player->get_hit_point()){
            ss << "\t\thit_point - " << old_player->get_hit_point()  << " -> " << new_player->get_hit_point() << "\n";
        }
        if(old_player->get_strength() != new_player->get_strength()){
            ss << "\t\tstrength - " << old_player->get_strength()  << " -> " << new_player->get_strength() << "\n";
        }
        if(old_player->get_endurance() != new_player->get_endurance()){
            ss << "\t\tendurance - " << old_player->get_endurance()  << " -> " << new_player->get_endurance() << "\n";
        }
        if(old_player->get_dexterity() != new_player->get_dexterity()){
            ss << "\t\tdexterity - " << old_player->get_dexterity()  << " -> " << new_player->get_dexterity() << "\n";
        }
        if(old_player->get_armor() != new_player->get_armor()){
            ss << "\t\tarmor - " << old_player->get_armor()  << " -> " << new_player->get_armor() << "\n";
        }
        if(old_player->get_coins() != new_player->get_coins()){
            ss << "\t\tcoins - " << old_player->get_coins()  << " -> " << new_player->get_coins() << "\n";
        }
        send(Message(ss.str(), game_structs_change));
        ss.clear();
        *old_player = *new_player;
    }
}
void Observer::log_dead_end(){
    //pref(error);
    send(Message("\tTry to step on not passable cell.\n", error));
}
void Observer::log_finish_game(GameStatus status){
    //pref(game_status);
    switch(status){
        case win:
            send(Message("\tGame is over. Player win.\n", game_status));
            break;
        case lose:
            send(Message("\tGame is over. Player lose.\n", game_status));
            break;
        case interrupt:
            send(Message("\tGame interrupt.\n", game_status));
            break;
        case restart:
            send(Message("\tGame restart.\n", game_status));
            break;
    }
}
void Observer::log_start_game(){
    send(Message("\tGame is start. \n", game_status));
}
void Observer::add_log(Log *l){
    logs.push_back(l);
}
void Observer::log_error(std::string text){
    send(Message(text, error));
}